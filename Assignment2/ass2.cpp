#include <iostream>
#include <GL/glut.h>
#include<math.h>
using namespace std;

int h = 640;
int w = 400;

static int menu_id;
static int submenu_id;
static int submenu_dotted_id;
static int submenu_dashed_id;

void myInit() {
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(15.0);
	gluOrtho2D(0,640,0,400);
}
void DDA_simple(float x1,float y1,float x2,float y2);
void Bresenham_simple(float x1,float y1,float x2,float y2);
void DDA_dotted(float x1,float y1,float x2,float y2);
void Bresenham_dotted(float x1,float y1,float x2,float y2);
void DDA_dashed(float x1,float y1,float x2,float y2); 
void Bresenham_dashed(float x1,float y1,float x2,float y2);

void mainMenu(int choice);
void submenu(int choice);
void submenu_dotted(int choice);
void submenu_dashed(int choice);

void coordinate() {
	glBegin(GL_LINES);
		glVertex2d(h/2,0);
		glVertex2d(h/2,w);
		glVertex2d(0,w/2);
		glVertex2d(h,w/2);
	glEnd();
	glFlush();
}
void MyDisplay(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	coordinate();
	
	

}
int main (int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(h,w);
	glutCreateWindow("Sample");
	
	glutDisplayFunc(MyDisplay);
	
	
	// menu 
	submenu_id=glutCreateMenu(submenu);
	glutAddMenuEntry("DDA",1);
	glutAddMenuEntry("BRESNHAM",2);
	
	// submenu for dotted line
	submenu_dotted_id=glutCreateMenu(submenu_dotted);
	glutAddMenuEntry("DDA",1);
	glutAddMenuEntry("BRESNHAM",2);
	
	// submenu for dashed line
	submenu_dashed_id=glutCreateMenu(submenu_dashed);
	glutAddMenuEntry("DDA",1);
	glutAddMenuEntry("BRESNHAM",2);
	
	// menu
	menu_id = glutCreateMenu(mainMenu);
	glutAddMenuEntry("MAIN MENU",0);
	glutAddSubMenu("SIMPLE LINE",submenu_id);
	glutAddSubMenu("DOTTED LINE",submenu_dotted_id);
	glutAddSubMenu("DASHED LINE",submenu_dashed_id);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	myInit();
	
	glutMainLoop();
	return 0;
}

void submenu(int choice) {
	//color = colors[choice];
	switch (choice) {
            case 1:
             	DDA_simple(10, 50, 100, 200);
            	break;
            
            case 2:
            	Bresenham_simple(50,10,200,100);
            	break;
		}
}

void submenu_dotted(int choice) {
	//color = colors[choice];
	switch (choice) {
            case 1:
             	DDA_dotted(10, 50, 100, 200);
            	break;
            
            case 2:
            	Bresenham_dotted(50,10,200,100);
            	break;
		}
}

void submenu_dashed(int choice) {
	//color = colors[choice];
	switch (choice) {
            case 1:
             	DDA_dashed(10, 50, 100, 200);
            	break;
            
            case 2:
            	Bresenham_dashed(50,10,200,100);
            	break;
		}
}

void mainMenu(int choice) {
	//color = colors[choice];
}

// DDA SIMPLE LINE 
void DDA_simple(float x1,float y1,float x2,float y2) {
	glPointSize(5.0);
	float dx = x2-x1;
	float dy = y2-y1;
	int steps = 0;
	float m = dy/dx;
	int i = 1;	
	float xi = x1,yi=y1;
	
	if(dx>dy)
		steps = abs(dx);
	else 
		steps = abs(dy);
	

		while(i<=steps) {
		
			glBegin(GL_POINTS);
    			glVertex2f(round(xi), round(yi));
    		glEnd();
    		glFlush();
    		
		    if(m<1) {
				xi += 1+xi;
				yi += m+yi;
			}
				
			else if(m==1) {
				xi += 1+xi;
				yi += 1+yi;
			}
			else if(m>1) {
				xi = 1/m+xi;
				yi = 1+yi;
			}
			i++;
		}	
}

void Bresenham_simple(float x1,float y1,float x2,float y2) {
	glPointSize(5.0);
	float dx = x2-x1;
	float dy = y2-y1;
	float pk = 2*dy-dx;
	float pi = pk;
	float xi = x1,yi=y1;
	
	while(xi<=x2&&yi<=y2) {
			glBegin(GL_POINTS);
    			glVertex2f(xi, yi);
    		glEnd();
    		glFlush();
    		
    		if(pi<0) {
    			pi = pk + 2*dy;
    			xi = xi+1;
    			yi = yi;
    		}
    		
    		else {
    			pi = pk + 2*(dy-dx);
    			xi = xi+1;
    			yi = yi+1;
    		}
	}
}


// DDA DOTTED LINE 
void DDA_dotted(float x1,float y1,float x2,float y2) {
	glPointSize(5.0);
	float dx = x2-x1;
	float dy = y2-y1;
	int steps = 0;
	float m = dy/dx;
	int i = 1;	
	float xi = x1,yi=y1;
	
	if(dx>dy)
		steps = abs(dx);
	else 
		steps = abs(dy);
	
		int count = 0;
		while(i<=steps) {
		
			glBegin(GL_POINTS);
			if(i%10==0)
    			glVertex2f(round(xi), round(yi));
    		glEnd();
    		glFlush();
    		
		    if(m<1) {
				xi += 1+xi;
				yi += m+yi;
			}
				
			else if(m==1) {
				xi += 1+xi;
				yi += 1+yi;
			}
			else if(m>1) {
				xi = 1/m+xi;
				yi = 1+yi;
			}

			i++;
		}	
}
// DOTTED BRESENHAM LINE
void Bresenham_dotted(float x1,float y1,float x2,float y2) {
	glPointSize(5.0);
	int i=0;
	float dx = x2-x1;
	float dy = y2-y1;
	float pk = 2*dy-dx;
	float pi = pk;
	float xi = x1,yi=y1;
	
	while(xi<=x2&&yi<=y2) {
			glBegin(GL_POINTS);
				if(i%10==0)
    				glVertex2f(xi, yi);
    		glEnd();
    		glFlush();
    		
    		if(pi<0) {
    			pi = pk + 2*dy;
    			xi = xi+1;
    			yi = yi;
    		}
    		
    		else {
    			pi = pk + 2*(dy-dx);
    			xi = xi+1;
    			yi = yi+1;
    		}
    		i++;
	}
}

// DASHED LINE

// DDA DASHED LINE
void DDA_dashed(float x1,float y1,float x2,float y2) {
	glPointSize(5.0);
	float dx = x2-x1;
	float dy = y2-y1;
	int steps = 0;
	float m = dy/dx;
	int i = 1;	
	float xi = x1,yi=y1;
	
	if(dx>dy)
		steps = abs(dx);
	else 
		steps = abs(dy);
	
		int count = 0;
		while(i<=steps) {
		
			glBegin(GL_POINTS);
			if(count<5)
    			glVertex2f(round(xi), round(yi));
    		glEnd();
    		glFlush();
    		
		    if(m<1) {
				xi += 1+xi;
				yi += m+yi;
			}
				
			else if(m==1) {
				xi += 1+xi;
				yi += 1+yi;
			}
			else if(m>1) {
				xi = 1/m+xi;
				yi = 1+yi;
			}
			count++;
			if(count==10)
				count = 0;
			i++;
		}	
}
// DASHED BRESENHAM LINE
void Bresenham_dashed(float x1,float y1,float x2,float y2) {
	glPointSize(5.0);
	int i=0;
	float dx = x2-x1;
	float dy = y2-y1;
	float pk = 2*dy-dx;
	float pi = pk;
	float xi = x1,yi=y1;
	
	while(xi<=x2&&yi<=y2) {
			glBegin(GL_POINTS);
				if(i<5)
    				glVertex2f(xi, yi);
    		glEnd();
    		glFlush();
    		
    		if(pi<0) {
    			pi = pk + 2*dy;
    			xi = xi+1;
    			yi = yi;
    		}
    		
    		else {
    			pi = pk + 2*(dy-dx);
    			xi = xi+1;
    			yi = yi+1;
    		}
    		i++;
    		if(i==10)
    			i=0;
    		
	}
}



