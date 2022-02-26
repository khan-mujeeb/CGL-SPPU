# CGL-SPPU
This repository contains the Assignment code of Computer Graphics  Assignments of SPPU, Second Year IT Syllabus (2019 pattern)

**OS used:** Ubuntu
## OpenGL installation on Ubuntu:
1. sudo apt-get update
2. sudo apt-get install freeglut3
3. sudo apt-get install freeglut3-dev
4. sudo apt-get install g++ cmake
5. sudo apt-get install libglew-dev
6. sudo apt-get install g++
7. sudo apt-get install mesa-common-dev
8. sudo apt-get install build-essential
9. sudo apt-get install libglew1.5-dev libglm-dev

## After your development libraries have been installed to get information about the OpenGL and GLX implementations running on a given X display.
glxinfo | grep OpenGL

## To Compile and Execute the C / C++ Program
1. g++ **filename.cpp** -lglut -lGL -lGLEW -lGLU -o **filename**
2. **./filename**
