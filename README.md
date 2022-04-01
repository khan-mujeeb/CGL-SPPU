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

# Basic Structure of OpenGL code
```c++:
	#include<iostream>
	#include<GL/glut.h>
	
	void Draw(){
		glClear(GL_COLOR_BUFFER_BIT);
		
		glPointSize(5);
		
		glBegin(GL_POINTS);
			glVertex2f(0,0);
		glEnd();
		glFlush();
	}
	
	int main(int c, char*V[]) {
		glutInit(&c,V);
		glutInitWindowSize(500,700);	
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		glutCreateWindow("Basic opengl program");
		
		glClearColor(0,0,0,1);	
		glColor3f(1,1,1);
		glutDisplayFunc(Draw);
		glutMainLoop();
		
		return 0;
	} 
```
* ## [code](https://github.com/khan-mujeeb/CGL-SPPU/tree/main/Basic%20Structure)
