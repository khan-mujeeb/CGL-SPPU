#include <iostream>
#include <GL/glut.h>
using namespace std;

int w=640;
int h= 480;

// *************Function Decleartion***************
void breshnam(float,float,float);
void plotpoint(float,float,float,float);
void myInit();
void MyDisplay();


// **************MAIN FUNCTION************************
int main(int argc, char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow(" Breshnam Circle");
	myInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}

// ***************** Myinit ********************
void myInit() {
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

// *************** My Display**************************
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
		glVertex2d(-w/2,0);
		glVertex2d(w/2,0);
		glVertex2d(0,-h/2);
		glVertex2d(0,h/2);
	glEnd();
	glFlush();
	
	breshnam(100,100,50);
	glFlush();

}

// **************** Breshnam *******************
void breshnam(float xc,float yc, float r) {
	int x,y;
	x=0;
	y=r;
	float s=3-2*r;
	
	while(x<=y) { 
		if(s<0)
			s=s+4*x+6;
		else {
			s=s+4*(x-y)+10;
			y--;
		}
		x++;
		plotpoint(xc,yc,x,y); 
	}
}

// ************** PlotPoint***************************
void plotpoint(float xc, float yc, float x, float y) {
	glBegin(GL_POINTS);
		glVertex2i(xc+x,yc+y);
		glVertex2i(xc+x,yc-y);
		glVertex2i(xc-x,yc+y);
		glVertex2i(xc-x,yc-y);
		glVertex2i(xc+y,yc+x);
		glVertex2i(xc+y,yc-x);
		glVertex2i(xc-y,yc+x);
		glVertex2i(xc-y,yc-x);
	glEnd();
	
	glFlush();

}
