hte_degradation_chamber
===========

## Description

This repository contains detailed instructions for building and using a low-cost, high-throughput aging test chamber for perovskite materials. The instructions and control programs are shared to facilitate more wide-spread aging testing among photovoltaic materials research as well as in other materials research fields.

This chamber has capability of controlling temperature of the samples, humidity of the degradation chamber, and illumination. Sample degradation can be followed by automated, color calibrated pictures. The implementation shown here accommodates 28 perovskite film samples. The aging chamber implemented according to the instructions typically $2,000-$5,000 depending on the amount of reused materials utilized in the process.

This chamber is the Generation 1 chamber in an open-hardware project for developing degradation chambers for perovskite materials (see figure below). The project is described in detail in article: [insert details]

![Degradation chamber generations in the open-hardware project. This repository describes MIT Gen. 1 chamber.](https://github.com/PV-Lab/hte_degradation_chamber/blob/main/Chamber_generations.png)

## Requirements

Installation instructions have been devloped for:
- Windows 10 64-bit or similar
- CAD software
- LabVIEW 2018 version 18.0
- ThorCam Version 3.2.1. and Windows SDK for DCx cameras version 4.80
- Arduino IDE version 1.8.9

## Installation

To install, clone this repository and the analysis codes repository. Either download the repository as a ZIP file, or use git:

`$ git clone https://github.com/PV-Lab/hte_degradation_chamber.git`

`$ git clone https://github.com/PV-Lab/RGBanalysis.git`

`$ cd hte_degradation_chamber`

Assembly of the degradation chamber:

- MIT Gen 1 Chamber Build Guide.pdf and the CAD drawing Chamber_MIT_Gen1.step

Installation of software in Windows 10 64-bit:

- Camera control and optional lamp intensity control
  - Connect the lamp and camera to the laptop according to the instructions in MIT Gen 1 Chamber Build Guide.pdf.
  - Install LabVIEW.
    - This setup has been implemented with LabVIEW 2018 version 18.0.
  - Install ThorLabs control software (ThorCam) and programming interface (Windows SDK for DCx cameras, specifically the LabVIEW interface) for the camera according to the instructions from ThorLabs.
    - This setup has been implemented for ThorLabs DCC1645C camera.
    - ThorCam software available for download in: https://www.thorlabs.com/software_pages/viewsoftwarepage.cfm?code=ThorCam
    - Drivers and programming interface available in: https://www.thorlabs.com/software_pages/ViewSoftwarePage.cfm?Code=ThorCam#tabs-139
    - This setup has been implemented using ThorCam Version 3.2.1. and Windows SDK for DCx cameras version 4.80.
  - Check according to the instructions in the ThorLabs camera manual that the camera is visible via ThorCam software. This indicates a successful installation of the drivers and software.
  - Open LabVIEW and run the desired version of the camera control program.
    - Camera_control_v4.vi: Current standard version. Controls the camera and saving of the pictures taken.
    - Camera_control_v5.vi: Same but expanded with automated control of lamp intensity (for dark testing or for low intensity testing). Lamp.vi is a sub-vi required by this control program.
    - Note: DCx_Camera_SDK/OtherDrivers/LabVIEW/uc480.NET/uc480_SimpleLive.vi: This standalone vi is included in the ThorLabs SDK and provides live image feed without saving any images. It is useful for testing camera settings.
- Humidity control
  - Connect the humidity-temperature sensor and Arduino to the laptop according to the instructions in MIT Gen 1 Chamber Build Guide.pdf.
  - Install Arduino programming interface according to the instructions from Arduino.
    - This setup has been implemented for Arduino Uno Rev2 SMD controller.
    - Arduino IDE software available for download: https://www.arduino.cc/en/software
    - This setup has been implemented using Arduino IDE version 1.8.9 for Windows 10.
  - Install Arduino control libraries for the humidity-temperature sensor.
    - This setup has been implemented for Adafruit Si7021 humidity-temperature sensor.
    -  In Arduino IDE: Open Sketch - Include Library - Manage libraries. Type in "Adafruit Si7021" and choose Install. Type in "Adafruit Unified Sensor" and choose Install.
    -  This setup has been implemented using Adafruit Si7021 library version 1.2.0 and Adafruit Unified Sensor library version 1.1.5.
  - Open Arduino programming interface and run the humidity control program.
    - Humidity_control_via_fan_v20220516/Humidity_control_via_fan_v20220516.ino
- Humidity tracking
  - Install EasyLog Humidity Tracker App according to the instructions from Lascar Electronics.
	- This setup has been implemented for Lascar Electronics EL-USB-2 sensor.
	- EasyLog App is available for download: https://www.lascarelectronics.com/software/easylog-software/easylog-usb

Use of the degradation chamber:

- MIT Gen 1 Chamber build guide.pdf

Analysis of the resulting picture data:

- Automated code with detailed instructions in: https://github.com/PV-Lab/RGBanalysis
- The code assumes 28 rectangular films with similar shape are being degraded on a sample holder in the picture area.
- The code slices the pictures to sub-pictures that contain only the individual samples, calculates the average color of each sample in red-green-blue (RGB) and LAB colors, and produces color vs. time csv files, pdfs of the degradation curves, and videos of the degrading samples as the outputs.
- The code produces both color calibrated and raw color data as a function of measurement time. The use of color calibration is essential for ensuring repeatable and reproducible results. The approach implemented here utilizes three-dimensional thin plate spline transformation and XRite ColorChecker Passport as a reference color chart with known colors. The color calibration process is described in detail in the ESI of this article: https://doi.org/10.1016/j.matt.2021.01.008

## Authors
||                    |
| ------------- | ------------------------------ |
| **AUTHORS**      | Alex Encinas, Clio Batali, Siyu I.P. Tian, Armi Tiihonen | 
| **VERSION**      | 1.0 / Jan, 2021     | 
| **EMAILS**      | isaactsy777@hotmail.com, armi.tiihonen@gmail.com | 
||                    |

## Attribution

License information:
- The content in the repository under MIT license

If you implement aging chambers or use the codes distributed in this repository, please acknowledge use of this work with the appropiate citation to the repository and research article.

## Citation

    @Misc{spproc2020,
      author =   {The hte_degradation_chamber authors},
      title =    {{hte_degradation_chamber}: low-cost and high-throughput degradation test chamber},
      howpublished = {\url{https://github.com/PV-Lab/hte_degradation_chamber}},
      year = {2020}
    }
    
    [insert article details here for the open hardware project]
    
    Shijing Sun, Armi Tiihonen, Felipe Oviedo, Zhe Liu, Janak Thapa, Yicheng Zhao, Noor Titan P. Hartono, Anuj Goyal, Thomas Heumueller, Clio Batali, Alex Encinas, Jason J. Yoo, Ruipeng Li, Zekun Ren, I. Marius Peters, Christoph J. Brabec, Moungi G. Bawendi, Vladan Stevanovic, John Fisher, Tonio Buonassisi, "A data fusion approach to optimize compositional stability of halide perovskites", Matter, 2021, https://doi.org/10.1016/j.matt.2021.01.008.
