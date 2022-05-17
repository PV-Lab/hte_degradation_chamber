// 

/*

    Humidity control via fan


    Control air humidity in an aging chamber by turning on/off a computer fan (connected to pin 4) that evaporates
    water from a container. An LED (connected to pin 13) is on when the system is running. It is recommendable to
    enable serial monitor printouts to ensure that the system runs properly.

    The circuit:

    Inputs:
    
    * SDA: I2C data pin for Si7021 sensor.
    
    
    Outputs:
    
    * GND: 3V power for the fan (-) via a transistor-resistor circuit.
    * Digital pin 4: Control computer fan (on/off) via a transistor-resistor circuit.
    
    * Digital pin 13: LED (+)
    * GND: LED (-)
    
    * SCL: I2C clock pin for Si7021 sensor.
    * 3V3: 3V power for Si7021 sensor.
    * GND: Ground for Si7021 sensor.
    
    the fan (+). If the power is not sufficient, connect also an external power source.
    
    Created 2019

    By Alex Encinas

    Modified 16.4.2022

    By Armi Tiihonen


    http://url/of/online/tutorial.cc


*/
//   =====================================================================================================
//   ================================          USER INPUT        =========================================
//   =====================================================================================================

float Desired_Humidity = 87; // Target air humidity in percentage value.
// Note: The humidity control setup operates via increasing air humidity from the initial value. Relative
// air humidities that are lower than that cannot be reached.
// Note: When altering the value, press Upload and wait until Arduino IDE reports "Done uploading" at the
// bottom of the screen (turquoise line). There should be only white text in the box with black background.
// If there is text with orange/red color, press Verify and Upload again. After you get "Done
// uploading", Press Tools - Serial monitor to get the print outs visible. Arduino should start printing
// out values in a couple of seconds.

float Tolerance = 0.0; // Turn the evaporation fan off at Desired_Humidity-Tolerance. Default value is 0%.

//   =====================================================================================================
//   ========================       SENSOR LIBRARY AND DECLARATION           =============================
//   =====================================================================================================

// Libraries required. These libraries which requires  to be installed
// To install "Adafruit Si7021 Library", go to Sketch -> Include Library -> Manage Libraries. Look up
// "Adafruit Si7021 Library" and click install.
#include "Adafruit_Si7021.h"
Adafruit_Si7021 sensor = Adafruit_Si7021(); //Declare the sensor and call it 'sensor'


//   =====================================================================================================
//   ==================      VARIABLE DECLARATION/ASSIGNMENT/CALCULATION         =========================
//   =====================================================================================================

#define DEBUG
 
#define FanPin 4  // The pin to which the fan is connected in Arduino. Default value: 4
#define LEDPin 13 // The pin to which the LED indicating the humidity control system runs is connected to.
// Default value: 13
float initial_wait_time = 30000; // Time (in milliseconds) from plugging Arduino in to the first time valve turns on.
float h; // Humidity reading (%)
float error_h; // The deviation of the current humidity value from the target humidity.
float pre_h = 0; // Humidity reading at the beginning of the loop.
float diff_h = 0; // The difference in the humidity reading between the beginning and end of the loop.
float loop_time = 5000; // Time (in milliseconds) before the system responds again

// PrintWriter output;



//   =====================================================================================================
//   ============================       SET-UP (ONE TIME CODE)         ===================================
//   =====================================================================================================
void setup() {
  
  Serial.begin(9600);
  while (!Serial) {   // Wait for serial port to open.
    delay(10);
  }
  sensor.begin(); // Initialize sensor Si7021.
  pinMode(FanPin,OUTPUT); // Initialize the pin where the solenoid is connected
  // (declared top of the file).
  pinMode(LEDPin,OUTPUT); // Initialize the pin where the indicator LED is connected (declared top of the file).

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
  delay(initial_wait_time); // Initial wait time for the system to start
  
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
    Serial.print("Error in RH:  ");
    Serial.print(error_h);
    Serial.print("%     ");    
    Serial.print("Change in RH in the previous step:  ");
    Serial.print(diff_h);
    Serial.println("%");
  #endif
 
  delay(1000);  // Short delay to make sure we don't take readings too fast (could mess up the sensor).

//   =====================================================================================================
//   =========================    DECISION MAKING (TURN ON OR WAIT)      =================================
//   =====================================================================================================

  if (h < (Desired_Humidity-Tolerance)) {
    digitalWrite(FanPin,HIGH); // Turn the valve on.
  }
  else {
    digitalWrite(FanPin,LOW); // Turn the valve off.
  }
  
    
    delay(loop_time); // Wait for the pre-set duration before going back to make another decision step.

  pre_h = h;



}
