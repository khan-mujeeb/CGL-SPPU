#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
void Draw();
void myInit();
void original();


// menu functions
void mainmenu(int i);
void translation_menu(int i);
void scaling_menu(int i);
void rotaion_menu(int i);

// transformation fuction
void translation(float,float);
void scaling(float,float);
void rotaion(int);

float tri[3][2] = {
						{0,0},
						{0.5,0},
						{0.5,0.5}
};
	
int main(int c, char*V[]) {
		glutInit(&c,V);
		glutInitWindowSize(500,700);	
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		glutCreateWindow("Basic opengl program");
		
		glutDisplayFunc(Draw);
		
		
		// sub menu
		int translation_id = glutCreateMenu(translation_menu);
			glutAddMenuEntry("along x-axis ",1);
			glutAddMenuEntry("along y-axis ",2);
			glutAddMenuEntry("along xy-axis ",3);
			
		int scaling_id = glutCreateMenu(scaling_menu);
			glutAddMenuEntry("along x-axis ",1);
			glutAddMenuEntry("along y-axis ",2);
			glutAddMenuEntry("along xy-axis ",3);
			
		int rotaion_id = glutCreateMenu(rotaion_menu);
			glutAddMenuEntry("clockwise",1);
			glutAddMenuEntry("Anticlockwise",2);
		
		
		//menu
		glutCreateMenu(mainmenu);
		glutAddMenuEntry("Main Menu",0);
		glutAddMenuEntry("Rest",1);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutAddSubMenu("Translation",translation_id);
		glutAddSubMenu("Scaling",scaling_id);
		glutAddSubMenu("Rotation",rotaion_id);
		
		
		glutMainLoop();
		return 0;
	} 
	
void Draw(){
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		original();
	}
	
void myInit() {
		glPointSize(5);
		glClearColor(0,0,0,1);	
		glColor3f(1,1,1);
}

void original() {
	glBegin(GL_LINE_LOOP);
		glVertex2f(tri[0][0],tri[0][1]);
		glVertex2f(tri[1][0],tri[1][1]);
		glVertex2f(tri[2][0],tri[2][1]);
	glEnd();
	glFlush();
}

void mainmenu(int i) {
	switch(i) {
		case 1: 
		glColor3f(1,1,1);
		Draw();
			break;
	}
	 
}

void translation_menu(int i){
	float tx = 0,ty = 0;
	switch(i) {
	
		case 1:
			cout<<"Enter tx ";
				cin>>tx;
			translation(tx,ty);
			break;
			
		case 2:
			cout<<"Enter ty ";
				cin>>ty;
			translation(tx,ty);
			break;
		
		case 3:
			cout<<"Enter tx ";
				cin>>tx;
			cout<<"Enter ty ";
				cin>>ty;
			translation(tx,ty);
			break;
	}
}



void translation(float tx,float ty) {
	glColor3f(0,1,1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(tri[0][0] + tx,tri[0][1] + ty);
		glVertex2f(tri[1][0] + tx,tri[1][1] + ty);
		glVertex2f(tri[2][0] + tx,tri[2][1] + ty);
	glEnd();
	glFlush();
}

// ********** scaling ************************
void scaling(float sx,float sy) {
	glColor3f(0,1,1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(tri[0][0] * sx,tri[0][1] * sy);
		glVertex2f(tri[1][0] * sx,tri[1][1] * sy);
		glVertex2f(tri[2][0] * sx,tri[2][1] * sy);
	glEnd();
	glFlush();
}

void scaling_menu(int i){
	float sx = 1,sy = 1;
	switch(i) {
	
		case 1:
			cout<<"Enter sx ";
				cin>>sx;
			translation(sx,sy);
			break;
			
		case 2:
			cout<<"Enter sy ";
				cin>>sy;
			translation(sx,sy);
			break;
		
		case 3:
			cout<<"Enter sx ";
				cin>>sx;
			cout<<"Enter sy ";
				cin>>sy;
			scaling(sx,sy);
			break;
	}
}

// **************roation******************
void rotaion_menu(int i) {
	int angle;
	cout<<"Enter Rotaion angle ";
		cin>>angle;
	float a = 0.017*angle;
	float x1 = tri[0][0]; 
	float y1 = tri[0][1];
	
	float x2 = tri[1][0];
	float y2 = tri[1][1];
	
	float x3 = tri[2][0];
	float y3 = tri[2][1];
	
	switch(i) {
		case 1:
			glColor3f(1,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(x1*cos(a)-y1*sin(a),x1*sin(a)+y1*cos(a));
				glVertex2f(x2*cos(a)-y2*sin(a),x2*sin(a)+y2*cos(a));
				glVertex2f(x3*cos(a)-y3*sin(a),x3*sin(a)+y3*cos(a));
			glEnd();
			glFlush();
			break;
		case 2:
			break;
	}
} 


// similarly we can do the shearing and refletion by using respective formula 
