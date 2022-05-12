 //   =====================================================================================================
//   ================================          USER INPUT        =========================================
//   =====================================================================================================
float Desired_Humidity = 87; // When modifying, press Upload and wait until it says "Done uploading" at the
// bottom of the screen (turquoise line). There should be only white text in the box with black background.
// If there is text with orange/red color, just press Verify and Upload again. After you get "Done
// uploading", Press Tools - Serial monitor to get the prin outs visible. Arduino should start printing
// values in a couple of seconds.
float Tolerance = 0.0; //turn blade off at Desired_Humidity-Tolerance
// Current file 20190802

//   =====================================================================================================
//   ========================       SENSOR LIBRARY AND DECLARATION           =============================
//   =====================================================================================================
//You need to include these libraries which requires "Adafruit Si7021 Library" to be installed
//To install, go to Sketch -> Include Library -> Manage Libraries. Look up "Adafruit Si7021 Library"
//And click install
#include "Adafruit_Si7021.h"
Adafruit_Si7021 sensor = Adafruit_Si7021(); //Declare the sensor and call it 'sensor'


//   =====================================================================================================
//   ==================      VARIABLE DECLARATION/ASSIGNMENT/CALCULATION         =========================
//   =====================================================================================================
#define DEBUG
 
#define SolenoidPin 4  //pin 4 is ideal for this use
#define LED 13
float initial_wait_time = 30000; //time from pluggin arduino in to first time valve turns on
float h; //humidity reading
float error_h;
float pre_h = 0;
float diff_h = 0;
float loop_time = 5000; //Time before system responds again
float initial_diff_sensitivity = 1.25; //responds when diff_h is below this value after loop_time seconds
float steady_diff_sensitivity = .5;
float differencial_sensitivity = initial_diff_sensitivity;
float time_valve_is_on = 5000;//in microseconds, how long does the valve turn on?
float stable_inflow_time = 5000; 
bool stable = false;
float max_on_time = 30000;  //In the initial path to getting stable, max RH introduced per logic loop
float error_percentage = .10; //percentage of target error that triggers between diff sensitivities
//PrintWriter output;



//   =====================================================================================================
//   ============================       SET-UP (ONE TIME CODE)         ===================================
//   =====================================================================================================
void setup() {
  
  Serial.begin(9600);
  while (!Serial) {   // wait for serial port to open
    delay(10);
  }
  sensor.begin();//initialize sensor Si7021
  pinMode(SolenoidPin,OUTPUT); //Initialize the pin where the solenoid is connected (declared top of the file)
  pinMode(LED,OUTPUT);

  #ifdef DEBUG
    Serial.print("Target Relative Humidity: ");
    Serial.print(Desired_Humidity);
    Serial.println("%");
    Serial.print("Tolerance: +-");
    Serial.print(Tolerance);
    Serial.println("%");  
    Serial.print("Initializing... getting accurate initial reading for sensor (delay = ");
    Serial.print(float(initial_wait_time/60000));
    Serial.println(" minutes)");
  #endif
  pre_h = sensor.readHumidity();
  delay(initial_wait_time); //Initial wait time for system to start
  
}


void loop() {
//   =====================================================================================================
//   =============================    CALCULATE CONTROL VARIABLES      ===================================
//   =====================================================================================================
  h = sensor.readHumidity();
  error_h = Desired_Humidity - h;
  diff_h = (h - pre_h);

  #ifdef DEBUG
    Serial.println(" ");
    Serial.print("Current RH:  ");
    Serial.print(h);
    Serial.print("%     ");
    Serial.print("Error RH:  ");
    Serial.print(error_h);
    Serial.print("%     ");    
    Serial.print("Change in RH:  ");
    Serial.print(diff_h);
    Serial.println("%");
  #endif

  
  delay(1000);  //short delay to make sure we don't take readings too fast (could mess up the sensor if not)

//   =====================================================================================================
//   =========================    DECISION MAKING (TURN ON OR WAIT)      =================================
//   =====================================================================================================
/*
  if (error_h > Tolerance) {

    
    if (error_h < (error_percentage*Desired_Humidity)) {//Changes the differential sesitivity to make it increase faster before it is stable
      differencial_sensitivity = steady_diff_sensitivity;
    }
    else {
      differencial_sensitivity = initial_diff_sensitivity;
    }

    if (h < Lower) { //varies that one_second_increase response based on the current humidity level of the chamber
      one_second_increase = x;
    }
    else if (h > Upper) {
      one_second_increase = y;
    }
    else {
      one_second_increase = (((y-x)/(Upper-Lower))*(h-Lower) + x);
    }
    
    
    if (diff_h < differencial_sensitivity ) {//Changes the amount of time the valve is on wrt the error
      if (!stable) {
        if (error_h < (one_second_increase*(max_on_time/1000))) {
          time_valve_is_on = (error_h/one_second_increase)*1000;
        }
        
        //else {
        //  time_valve_is_on = max_on_time;
        //}
        
        if ((time_valve_is_on < 0) || (time_valve_is_on > max_on_time)) {
          time_valve_is_on = max_on_time;
        }
      }
      
      digitalWrite(SolenoidPin,HIGH);
      digitalWrite(LED,HIGH);
      delay(time_valve_is_on);
      digitalWrite(SolenoidPin,LOW);
      digitalWrite(LED,LOW);
      
      #ifdef DEBUG
        Serial.print("Turned Valve On for ");
        Serial.print(time_valve_is_on/1000); 
        Serial.println(" seconds");
        Serial.print("One Second Increase: ");
        Serial.print(one_second_increase); 
        Serial.println("% humidity");
        //Serial.print("Stable: ");
        //Serial.println(stable); 
        //Serial.print("Value of interest (error_h/one_second_increase): ");
        //Serial.println(error_h/one_second_increase); 
      #endif
    }

    else {
      #ifdef DEBUG
        Serial.println("Valve Remained Close. System Not Stable.");
      #endif
    }

  }
  else {
    stable = true;
    time_valve_is_on = stable_inflow_time; 
    #ifdef DEBUG
       Serial.println("Valve Remained Closed. System Stable.");
    #endif
  }
  */

  if (h < (Desired_Humidity-Tolerance)) {
    digitalWrite(SolenoidPin,HIGH);
  }
  else {
    digitalWrite(SolenoidPin,LOW);
  }
  
    
    delay(loop_time); //wait two minute before going back to make another decision

  pre_h = h;



}
