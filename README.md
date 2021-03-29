# hte_degradation_chamber

This repository contains detailed instructions for building and using a low-cost, high-throughput aging test chamber. The instructions and control programs are shared in the hope of triggering more wide-spread aging testing among photovoltaic materials research as well as in other materials research fields.

This chamber has capability of controlling temperature of the samples, humidity of the degradation chamber, and illumination. Sample degradation can be followed by automated, color calibrated pictures. The implementation shown here accommodates 28 perovskite film samples. The aging chamber implemented according to the instructions typically $2,000-$5,000 depending on the amount of reused materials utilized in the process.

Assembly and use of a degradation chamber:
- Degradation_chamber_SOP.pdf

Installation of software:
- Install LabVIEW.
- Install ThorLabs control software and programming interface for camera
- Open LabVIEW and run the desired version of the camera control program.
  - V4: Current standard version.
  - V5: Same but with automated control of lamp intensity.
  - SimpleLive: Run this if you don't want to save any images.
- Install Arduino programming interface.
- Open Arduino programming interface and run the humidity control program.
  - Fan_humidityControl.ino

Analysis of the resulting picture data:
- Automated code in: https://github.com/PV-Lab/RGBanalysis
- The code produces both color calibrated and raw color data as a function of measurement time. The use of color calibration is essential for ensuring repeatable and reproducible results. Approach implemented is described in detail in the ESI of the following article: https://doi.org/10.1016/j.matt.2021.01.008

License information:
- uc480_XX.vi files are part of the programming interface of ThorLabs cameras that is distributed by ThorLabs. These files are included only to aid debugging in case that a newer programming interface for these cameras is installed. All the use of these files follows the licensing defined by ThorLabs and should be considered separately for the rest of the material in this repository.
- All the other content and the implementation of aging chambers according to the instructions described here follows MIT license.

Citations:
- If you implement aging chambers or use the codes distributed in this repository, please cite:
  - This repository as: "XX"
  - C2a?

Authors:
To do
