#include<iostream>
#include<GL/glut.h>

int h = 600;
int w = 700;
void myInit();
void draw();
void quadrant();

int main(int c,char *v[]) {
	glutInit(&c,v);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(h,w);
	glutCreateWindow("Assignemnt 5");
	myInit();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

void myInit() {
	glPointSize(5);
	glClearColor(0,0,0,1);
	glColor3f(1,1,1);
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	quadrant();
	glFlush();
}

void quadrant() {	
	glBegin(GL_LINES);
		glVertex2d(h/2,0);
		glVertex2d(-h/2,0);
		glVertex2d(0,w/2);
		glVertex2d(0,-w/2);
	glEnd();
	glFlush();
}

