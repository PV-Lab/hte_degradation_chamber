hte_degradation_chamber
===========

## Description

This repository contains detailed instructions for building and using a low-cost, high-throughput aging test chamber. The instructions and control programs are shared in the hope of triggering more wide-spread aging testing among photovoltaic materials research as well as in other materials research fields.

This chamber has capability of controlling temperature of the samples, humidity of the degradation chamber, and illumination. Sample degradation can be followed by automated, color calibrated pictures. The implementation shown here accommodates 28 perovskite film samples. The aging chamber implemented according to the instructions typically $2,000-$5,000 depending on the amount of reused materials utilized in the process.

## Installation

To install, just clone this repository and analysis codes repository:

`$ git clone https://github.com/PV-Lab/hte_degradation_chamber.git`

`$ git clone https://github.com/PV-Lab/RGBanalysis.git`

`$ cd hte_degradation_chamber`

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

## Authors
||                    |
| ------------- | ------------------------------ |
| **AUTHORS**      | Alex Encinas, Clio Batali, Siyu I.P. Tian, Armi Tiihonen | 
| **VERSION**      | 1.0 / Jan, 2021     | 
| **EMAILS**      | isaactsy777@hotmail.com, armi.tiihonen@gmail.com | 
||                    |

## Attribution

License information:
- uc480_XX.vi files are part of the programming interface of ThorLabs cameras that is distributed by ThorLabs. These files are included only to aid debugging in case that a newer programming interface for these cameras is installed. All the use of these files follows the licensing defined by ThorLabs and should be considered separately for the rest of the material in this repository.
- All the other content and the implementation of aging chambers according to the instructions described here is under MIT license.

If you implement aging chambers or use the codes distributed in this repository, please acknowledge use of this work with the appropiate citation to the repository and research article.

## Citation

    @Misc{spproc2020,
      author =   {The hte_degradation_chamber authors},
      title =    {{hte_degradation_chamber}: low-cost and high-throughput degradation test chamber},
      howpublished = {\url{https://github.com/PV-Lab/hte_degradation_chamber}},
      year = {2020}
    }
    
    Shijing Sun, Armi Tiihonen, Felipe Oviedo, Zhe Liu, Janak Thapa, Yicheng Zhao, Noor Titan P. Hartono, Anuj Goyal, Thomas Heumueller, Clio Batali, Alex Encinas, Jason J. Yoo, Ruipeng Li, Zekun Ren, I. Marius Peters, Christoph J. Brabec, Moungi G. Bawendi, Vladan Stevanovic, John Fisher, Tonio Buonassisi, "A data fusion approach to optimize compositional stability of halide perovskites", Matter,
2021, https://doi.org/10.1016/j.matt.2021.01.008.
