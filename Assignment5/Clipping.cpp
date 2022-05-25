#include <iostream>
using namespace std;
#include<string.h>
#include<GL/glut.h>

#include<math.h>
double Xmin, Ymin, Xmax, Ymax, X1, Y1, X2, Y2;
int x, y, temp;
const int L=8, R=4, B=2, T=1;   //for four bit code value
int calCode(double x, double y)	//to calculate outcode for endpoints of line
{
//p1 =10,40   p2=30 70

	int code=0;
	if(x>Xmax)
	code= R;//0010
	if(x<Xmin)        //out code is the unit code given to end pts to end pts of line (abrl-above,below,right left) , corners arent checked because all condition are not checked ...only if is used so outcode is added .... if ..else is not used
	code= L;
	if(y>Ymax)
	code= T;
	if(y<Ymin)
	code= B;
	return(code);
}

void LineClip(double X1, double Y1, double X2, double Y2)
{
	unsigned int outcode1 , outcode2;
	int accept=0, done=0;
	float M= float(Y2-Y1)/(X2-X1);	//slope of line
	outcode1=calCode(X1,Y1);    //To calculate end points outcode value
	outcode2=calCode(X2,Y2);
	do
	{
		if(outcode1==0 && outcode2==0)	//completely visible line(inside the window)
		{
			accept=1;
			done=1;
		}
		else if((outcode1 & outcode2)!=0)	//completely invisible line.... single & is for logical anding(completely outside of window)
		{
			done=1;
		}
		else
		{

			if(outcode1==0)//p1	//if one endpoint is completely inside the window
			temp=outcode2;  //temp=p2 bit code
			else
			temp=outcode1;

if(temp & T)	//if  the point intersects at the top
			{
				y=Ymax;
				x= X1 + (Ymax-Y1)/M;
			}
			else if(temp & B )	//if  the point intersects at the bottom
			{
				y= Ymin;
				x= X1 + (Ymin-Y1)/M;
			}
			else if(temp & L)	//if  the point intersects at the left
			{
				x= Xmin;
				y= Y1 + M*(Xmin-X1);
			}
			else if(temp & R)	//if  the point intersects at the right
			{
				x= Xmax;
				y= Y1+ M*(Xmax-X1);
			}

			if(temp==outcode1)
			{
				X1= x;
				Y1= y;
				outcode1=calCode(X1,Y1);
			}
			if(temp==outcode2)
			{
				X2= x;
				Y2= y;
				outcode2=calCode(X2,Y2);
			}

		}
	}while(done==0);


if(accept)			//Plot only those points for which accept is equal to 1
	{

		glColor3f(0.0,0.0,1.0);// blue line
		glBegin(GL_LINES);
		glVertex2d(X1,Y1);
		glVertex2d(X2,Y2);
		glEnd();

	}
}


void display(void)
{
 	glClear(GL_COLOR_BUFFER_BIT);

 	glBegin(GL_LINE_LOOP);
 	glColor3f(1.0,1.0,1.0);
	glVertex2d(Xmin,Ymin);	//for drawing the window
	glVertex2d(Xmax,Ymin);
	glVertex2d(Xmax,Ymax);
	glVertex2d(Xmin,Ymax);
	glEnd();
	glBegin(GL_LINE_STRIP);

	glVertex2d(X1,Y1);		//for drawing the line
	glVertex2d(X2,Y2);
	glEnd();
	LineClip(X1,Y1,X2,Y2);

	glFlush();
}
void myinit()
{
  	glClearColor(0.0,0.0,0.0,0.0); 			//set background as black
  	glColor3f(0.0,0.0,0.0);   				// Draw in white
  	gluOrtho2D(0.0,650.0,0.0,650.0);
}

int main(int argc, char **argv)
{
	cout<<"Enter the  coordinates of window:";
 	cout<<"\nEnter Point1( Xmin , Ymin):";
  	cin>>Xmin>>Ymin;
	cout<<"\nEnter Point2( Xmax , Ymax):";
  	cin>>Xmax>>Ymax;

	cout<<"Enter two end points of the line to be drawn:";
 	cout<<"\nEnter Point1( X1 , Y1):";
  	cin>>X1>>Y1;
	cout<<"\nEnter Point2( X2 , Y2):";
  	cin>>X2>>Y2;
  	cout<<"\nAfter Clipping";

  	glutInit(&argc,argv);  						//Initialize toolkit
	glutInitDisplayMode(GLUT_SINGLE  | GLUT_RGB);  				//set display mode
	glutInitWindowSize(650,650); 					//Set window size
	glutInitWindowPosition(0,0); 					//set window position on screen
								//Open screen window
	glutCreateWindow("Line Clipping");
	myinit();
	glutDisplayFunc(display);



	glutMainLoop();
	return 0;
}


