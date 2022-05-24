

#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>

using namespace std;
#define s 0.86602540
int n;

void koch(int x1,int y1,int x2,int y2,int m) {
	int x[5],y[5];
	x[0] = x1;
	y[0] = y1;
	
	x[4] = x2;
	y[4] = y2;
	
	cout<<x2<<" "<<y2;
	int lx = (x2-x1)/3;
	int ly = (y2-y1)/3;
	
	x[1] = x[0] + lx ;
	y[1] = y[0] + ly ;
	
	x[3] = (x[0] + (2*lx));
	y[3] = y[0] + (2*ly);
	
	int xx = x[3]-x[1];
	int yy = y[3]-y[1]; 
	
	x[2] = x[1]+(xx*(0.5) + yy*s) ;
	y[2] = y[1]+(yy*(0.5) - xx*s) ;
	
	if(m>0){
		koch(x[0],y[0],x[1],y[1],m-1);
		koch(x[1],y[1],x[2],y[2],m-1);
		koch(x[2],y[2],x[3],y[3],m-1);
		koch(x[3],y[3],x[4],y[4],m-1);
	}
	else {
glBegin(GL_LINES);
	 	glVertex2d(x[0], y[0]);
		glVertex2d(x[1] , y[1] );
		glEnd();
		
		glBegin(GL_LINES);
	 	glVertex2d(x[1], y[1]);
		glVertex2d(x[2] , y[2] );
		glEnd();
		
		glBegin(GL_LINES);
	 	glVertex2d(x[2], y[2]);
		glVertex2d(x[3] , y[3] );
		glEnd();
		
		glBegin(GL_LINES);
	 	glVertex2d(x[3], y[3]);
		glVertex2d(x[4] , y[4] );
		glEnd();
		glFlush();
	}
	

}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	int x1=0,x2=550,y1=200,y2=200;
	koch(x1,y1,x2,y2,n);
	glFlush();
}
void myinit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	gluOrtho2D(0.0,650.0,650.0,0.0);
}


int main(int argc,char **argv)
{
	cout<<"\nEnter the level of curve generation : ";
	cin>>n;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(650,650);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Koch Curve");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}





