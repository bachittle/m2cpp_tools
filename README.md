# Matlab to C++ Translation Kit

This repository contains utility functions for writing your own matlab to C++ translations.
It is not meant to be a full-scale automatic translator, but rather a starting point for you to write your own translations manually.

If you want to run matlab code in C++, use the [matlab coder plugin](https://www.mathworks.com/help/coder/ug/cpp-code-generation.html) if you have access to it, 
or [Octave](https://docs.octave.org/interpreter/Standalone-Programs.html#Standalone-Programs) if you want an open source solution.

If you instead are looking to translate matlab code to C++ and attempt to make it more efficient, this repository is for you.

## Installation

The source code for this package is header-only. However it depends on the following packages:
- Eigen3

This is because all the translations I do use Eigen. A potential update in the future could omit Eigen and be more generic.

To use this library in your own project, refer to the CMakeLists.txt to see how I use it for my sample executables.