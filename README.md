 # MTK (Music ToolKit)
 A C++ API designed for Music software

 ![MTK Version](https://img.shields.io/github/v/tag/qoolander/MTK?label=Version)
 ![Build](https://github.com/qoolander/MTK/workflows/Build/badge.svg?branch=Development)
 ![codecov](https://codecov.io/gh/qoolander/MTK/branch/Development/graph/badge.svg)



 This project is a work in progress, many features are not implemented and API likely to change. 

 ## Contents
 * [Goals](#goals)
 * [Current features](#current-features)
 * [Building from source](#building-from-source)
 * [License](#license)
 

 ## Goals
 ###### Highest priority first
 * Define an API flexible enough to deal with music outside of Western traditions
 * Interface with existing standards: 
   * Midi
   * MusicXML
 * A python wrapper to access through scripting language
 * Basic synthesis capabilities
 * Notation rendering 
 
 ## Current features
 * See the state of the current API in [the docs](/docs)
 
 ## Building from source
 ### Dependencies
  * [CMake](https://gitlab.kitware.com/cmake/cmake) - minimum version tested on version 3.16
  * A C++11-standard-compliant compiler
  
 ```
 git clone https://github.com/qoolander/MTK.git
 cd MTK
 mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=debug -DTests=OFF -BUILD_DOCUMENTATION=OFF ..
 cmake --build build --target all -- -j 4
 ```
 
 ## Built using
 * [gtest](https://github.com/google/googletest)
 * [Doxygen](https://github.com/doxygen/doxygen)
 * [Eigen3](https://gitlab.com/libeigen/eigen)
 * [PortAudio](http://portaudio.com/docs/v19-doxydocs/index.html)
 
 ## License
Developed under GNU General Public License Version 3. [See full LICENSE](LICENSE) 
 
