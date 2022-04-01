
// Header file
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
		glutInitWindowSize(500,700);	// w h
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		glutCreateWindow("Basic opengl program");
		
		glClearColor(0,0,0,1);	//set background color
		glColor3f(1,1,1);
		glutDisplayFunc(Draw);	// display calll back function 
		glutMainLoop();
		
		return 0;
	} 


