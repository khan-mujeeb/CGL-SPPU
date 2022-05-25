#include <iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
int option ;
struct Point // stores pixel to color pixel by pixel 
{
	int x;
	int y;
};

struct Color    // represents color model 
{
	float r;
	float g;
	float b;
};

Color getPixelColor(int x, int y)  // for getting color of pixel ...user defined function .... used to give color seedpoint which is inside polygon ... 
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);  //inbuilt function .gives x,y ..									ht and wdth of pixel , 						color model and datatype , address of structure object is 					passed it means the color which glreadpixels identitifies ..					that color is stored in form of rgb model which is returned 
	return color;
}

void setPixelColor(int x, int y, Color color)   //set color of pixel..user defined function ...to give color effect to selected pixel ...
{
	glColor3f(color.r, color.g, color.b);   // color selected above in form rgb model ..its selects the color in the coloring pane created to fill the polygon 
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}








void bFill(int x, int y, Color oColor, Color bColor)
{
	Color color;
	color = getPixelColor(x, y);
	if ((color.r != oColor.r || color.g != oColor.g || color.b != oColor.b) && (color.r != bColor.r || color.g != bColor.g || color.b != bColor.b)) {
		setPixelColor(x, y, oColor);
		bFill(x + 1, y, oColor, bColor);
		bFill(x, y + 1, oColor, bColor);
		bFill(x - 1, y, oColor, bColor);
		bFill(x, y - 1, oColor, bColor);

	}
	return;
	glFlush();
}




void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(100,100);
	glVertex2f(400,100);
	glVertex2f(400,100);
	glVertex2f(400,400);
	glVertex2f(100,400);
	glVertex2f(400,400);
	glVertex2f(100,100);
	glVertex2f(100,400);
	glEnd();
	glFlush();//send all output to display
}

void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //set background as black
	glColor3f(1.0, 1.0, 1.0);    
	glPointSize(1.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myMouse(int button, int state, int x, int y)
{
	
	
	Color bColor = { 1.0f,1.0f,1.0f };
	Color oColor = { 1.0f,0.0f,0.0f };
	
		bFill(x, y, oColor, bColor);
}



	int main (int argc, char** argv)
	{
		glutInit (&argc, argv); //Initialize toolkit
		glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //set display mode
		glutInitWindowSize (640, 480); //Set window size
		glutInitWindowPosition(0, 0); //set window position on screen
		//Open screen window
		glutCreateWindow ("Polygon filling using seed feel & boundary fill");
				glutDisplayFunc(display);  //Register redraw func
		
		glutMouseFunc(myMouse);
		myinit();
		glutMainLoop();
		return 0;
	}
