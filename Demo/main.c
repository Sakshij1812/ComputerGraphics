#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include<string.h>
#include<string.h>
/* ASCII -escape key. */
#define ESCAPE 27
#define FPS 9

GLint window;
GLint window2;
GLint Xsize=1366;
GLint Ysize=683;
float i,theta;

void timer_callback(int);

GLfloat xt=0.0,yt=0.0,zt=0.0,xw=0.0;
GLfloat tx=295,ty=62;
GLfloat angle=0.0;
GLfloat r=4,g=3,b=0;
int view=0;
GLUquadricObj *t;

static void SpecialKeyFunc( int Key, int x, int y );

/* Simple  transformation routine */
GLvoid Transform(GLfloat Width, GLfloat Height)
{
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,Width/Height,0.1,100.0);
	glMatrixMode(GL_MODELVIEW);
}


GLvoid InitGL(GLfloat Width, GLfloat Height)
{

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLineWidth(2.0);
	Transform( Width, Height );
	t=gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);

}

void init()
{
	glClearColor(0,0,0,0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,900.0,0.0,600.0,50.0,-50.0);
}

void display_string(int x, int y, char *string, int font)
{
	int len,i;
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		if(font==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
		else if(font==2)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
		else if(font==3)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
		else if(font==4)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}

//FRONT PAGE
void display1(void)
{

	glClearColor(0.111,0.111,0.111,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	display_string(320,540,"PES INSTITUTE OF TECHNOLOGY",1);
	display_string(215,500,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",1);
	display_string(380,440,"A MINI PROJECT ON:",2);
	display_string(310,410,"MOBILE AND SATELLITE COMMUNICATION",2);
	display_string(420,310,"BY:",2);
	display_string(380,280,"SAKSHI JAIN",3);
	display_string(380,260,"SHRADDHA SHETTY",3);
	display_string(350,150,"PRESS SPACE BAR TO ENTER",2);
	display_string(410,120,"ESCAPE TO EXIT",4);
	glutSwapBuffers();

}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

//***************OBJECTS****************//
void Car(){
	InitGL(Xsize,Ysize);
	glClearColor(0.5,0.6,0.9,1);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-6.0,-2.6,-9.0);
	glTranslatef(xt,yt,zt);
	glEnable(GL_COLOR_MATERIAL);

	glBegin(GL_QUADS);                /* OBJECT MODULE*/

	/* top of cube*/
	//************************FRONT BODY****************************************
	glColor3f(r,g,b);
	glVertex3f( 0.2, 0.4,0.6);
	glVertex3f(0.6, 0.5,0.6);
	glVertex3f(0.6, 0.5,0.2);
	glVertex3f( 0.2,0.4,0.2);

	/* bottom of cube*/
	glVertex3f( 0.2,0.2,0.6);
	glVertex3f(0.6,0.2,0.6);
	glVertex3f(0.6,0.2,0.2);
	glVertex3f( 0.2,0.2,0.2);

	/* front of cube*/
	glVertex3f( 0.2,0.2,0.6);
	glVertex3f(0.2, 0.4,0.6);
	glVertex3f(0.2,0.4,0.2);
	glVertex3f( 0.2,0.2,0.2);

	/* back of cube.*/
	glVertex3f(0.6,0.2,0.6);
	glVertex3f(0.6,0.5,0.6);
	glVertex3f(0.6,0.5,0.2);
	glVertex3f( 0.6,0.2,0.2);

	/* left of cube*/
	glVertex3f(0.2,0.2,0.6);
	glVertex3f(0.6,0.2,0.6);
	glVertex3f(0.6,0.5,0.6);
	glVertex3f(0.2,0.4,0.6);

	/* Right of cube */
	glVertex3f(0.2,0.2,0.2);
	glVertex3f( 0.6,0.2,0.2);
	glVertex3f( 0.6,0.5,0.2);
	glVertex3f( 0.2,0.4,0.2);
	//****************************************************************************
	glVertex3f(0.7,0.65,0.6);
	glVertex3f(0.7,0.65,0.2);
	glVertex3f(1.7,0.65,0.2);        //top cover
	glVertex3f(1.7,0.65,0.6);
	//***************************back guard******************************
	glColor3f(r,g,b);            /* Set The Color To Yellow*/
	glVertex3f( 1.8, 0.5,0.6);
	glVertex3f(1.8, 0.5,0.2);
	glVertex3f(2.1, 0.4, 0.2);
	glVertex3f(2.1,0.4,0.6);

	/* bottom of cube*/
	glVertex3f( 2.1,0.2,0.6);
	glVertex3f(2.1,0.2,0.2);
	glVertex3f(1.8,0.2,0.6);
	glVertex3f( 1.8,0.2,0.6);

	/* back of cube.*/
	glVertex3f(2.1,0.4,0.6);
	glVertex3f(2.1,0.4,0.2);
	glVertex3f(2.1,0.2,0.2);
	glVertex3f(2.1,0.2,0.6);

	/* left of cube*/
	glVertex3f(1.8,0.2,0.2);
	glVertex3f(1.8,0.5,0.2);
	glVertex3f(2.1,0.4,0.2);
	glVertex3f(2.1,0.2,0.2);

	/* Right of cube */
	glVertex3f(1.8,0.2,0.6);
	glVertex3f(1.8,0.5,0.6);
	glVertex3f(2.1,0.4,0.6);
	glVertex3f(2.1,0.2,0.6);
	//******************MIDDLE BODY************************************
	glVertex3f( 0.6, 0.5,0.6);
	glVertex3f(0.6, 0.2,0.6);
	glVertex3f(1.8, 0.2, 0.6);
	glVertex3f(1.8,0.5,0.6);

	/* bottom of cube*/
	glVertex3f( 0.6,0.2,0.6);
	glVertex3f(0.6,0.2,0.2);
	glVertex3f(1.8,0.2,0.2);
	glVertex3f( 1.8,0.2,0.6);

	/* back of cube.*/
	glVertex3f(0.6,0.5,0.2);
	glVertex3f(0.6,0.2,0.2);
	glVertex3f(1.8,0.2,0.2);
	glVertex3f(1.8,0.5,0.2);
	//*********************ENTER WINDOW**********************************
	glColor3f(0.3,0.3,0.3);
	glVertex3f( 0.77, 0.63,0.2);
	glVertex3f(0.75, 0.5,0.2);        //quad front window
	glVertex3f(1.2, 0.5, 0.2);
	glVertex3f( 1.22,0.63,0.2);

	glVertex3f(1.27,0.63,.2);
	glVertex3f(1.25,0.5,0.2);        //quad back window
	glVertex3f(1.65,0.5,0.2);
	glVertex3f(1.67,0.63,0.2);

	glColor3f(r,g,b);
	glVertex3f(0.7,0.65,0.2);
	glVertex3f(0.7,0.5,.2);       //first separation
	glVertex3f(0.75,0.5,0.2);
	glVertex3f(0.77,0.65,0.2);

	glVertex3f(1.2,0.65,0.2);
	glVertex3f(1.2,0.5,.2);       //second separation
	glVertex3f(1.25,0.5,0.2);
	glVertex3f(1.27,0.65,0.2);

	glVertex3f(1.65,0.65,0.2);
	glVertex3f(1.65,0.5,.2);     //3d separation
	glVertex3f(1.7,0.5,0.2);
	glVertex3f(1.7,0.65,0.2);

	glVertex3f( 0.75, 0.65,0.2);
	glVertex3f(0.75, 0.63,0.2);        //line strip
	glVertex3f(1.7, 0.63, 0.2);
	glVertex3f( 1.7,0.65,0.2);

	glVertex3f( 0.75, 0.65,0.6);
	glVertex3f(0.75, 0.63,0.6);        //line strip
	glVertex3f(1.7, 0.63, 0.6);
	glVertex3f( 1.7,0.65,0.6);

	glColor3f(0.3,0.3,0.3);
	glVertex3f( 0.77, 0.63,0.6);
	glVertex3f(0.75, 0.5,0.6);        //quad front window
	glVertex3f(1.2, 0.5, 0.6);
	glVertex3f( 1.22,0.63,0.6);

	glVertex3f(1.27,0.63,.6);
	glVertex3f(1.25,0.5,0.6);        //quad back window
	glVertex3f(1.65,0.5,0.6);
	glVertex3f(1.67,0.63,0.6);

	glColor3f(r,g,b);
	glVertex3f(0.7,0.65,0.6);
	glVertex3f(0.7,0.5,.6);       //first separation
	glVertex3f(0.75,0.5,0.6);
	glVertex3f(0.77,0.65,0.6);

	glVertex3f(1.2,0.65,0.6);
	glVertex3f(1.2,0.5,.6);       //second separation
	glVertex3f(1.25,0.5,0.6);
	glVertex3f(1.27,0.65,0.6);

	glVertex3f(1.65,0.65,0.6);
	glVertex3f(1.65,0.5,.6);
	glVertex3f(1.7,0.5,0.6);
	glVertex3f(1.7,0.65,0.6);
	glEnd();


	//**************************************************************
	glBegin(GL_QUADS);

	/* top of cube*/
	glColor3f(0.3,0.3,0.3);
	glVertex3f( 0.6, 0.5,0.6);
	glVertex3f(0.6, 0.5,0.2);        //quad front window
	glVertex3f(0.7, 0.65, 0.2);
	glVertex3f( 0.7,0.65,0.6);

	glVertex3f(1.7,0.65,.6);
	glVertex3f(1.7,0.65,0.2);        //quad back window
	glVertex3f(1.8,0.5,0.2);
	glVertex3f(1.8,0.5,0.6);
	//*************************************************************************************************

	/* top of cube*/
	glColor3f(0.3,0.3,0.3);
	glVertex3f( 0.6, 0.5,0.6);
	glVertex3f( 0.7,0.65,0.6);       //tri front window
	glVertex3f(0.7,0.5,0.6);

	glVertex3f( 0.6, 0.5,0.2);
	glVertex3f( 0.7,0.65,0.2);       //tri front window
	glVertex3f(0.7,0.5,0.2);
	glVertex3f( 1.7, 0.65,0.2);
	glVertex3f( 1.8,0.5,0.2);       //tri back window
	glVertex3f( 1.7,0.5,0.2);

	glVertex3f( 1.7, 0.65,0.6);
	glVertex3f( 1.8,0.5,0.6);       //tri back window
	glVertex3f(1.7,0.5,0.6);

	glEnd();
	//********************WHEEL*********************************************

	glColor3f(0.7,0.7,0.7);
	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+70)
	{
		glVertex3f(0.6,0.2,0.62);
		glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+70)
	{
		glVertex3f(1.7,0.2,0.62);
		glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	}
	glEnd();
	glTranslatef(0.6,0.2,0.6);
	glColor3f(0,0,0);
	glutSolidTorus(0.025,0.07,10,25);

	glTranslatef(0,0,-0.4);
	glutSolidTorus(0.025,0.07,10,25);

	glTranslatef(1.1,0,0);
	glutSolidTorus(0.025,0.07,10,25);

	glTranslatef(0,0,0.4);
	glutSolidTorus(0.025,0.07,10,25);
	//*************************************************************
	glEnable(GL_DEPTH_TEST);
}

GLvoid home()
{
	//Roof
	glColor3f(0.3, 0.5, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(2.00, 5.00);
	glVertex2f(6.00, 5.00);
	glVertex2f(7.00, 3.50);
	glVertex2f(3.00, 3.50);
	glEnd();

	//Roof line
	glColor3f(0.0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.00, 5.00);
	glVertex2f(6.00, 5.00);
	glVertex2f(7.00, 3.50);
	glVertex2f(3.00, 3.50);
	glEnd();

	// Top of Front Wall
	glColor3f(0.1, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(2.00, 5.00);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glEnd();

	// Top of Front Wall Line
	glColor3f(0, 0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.00, 5.00);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glEnd();

	// Front Door Lock
	glColor3f(0.3, 0.7, 0.9);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(2.30, 2.10);
	glEnd();

	// Front Door
	glColor3f(0.7, 0.2, 0.9);
	glBegin(GL_POLYGON);
	glVertex2f(1.50, 3.50);
	glVertex2f(2.50, 3.0);
	glVertex2f(2.50, 1.23);
	glVertex2f(1.50, 1.80);
	glEnd();

	// Front Door Line
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.50, 3.50);
	glVertex2f(2.50, 3.0);
	glVertex2f(2.50, 1.23);
	glVertex2f(1.50, 1.80);
	glEnd();

	// Front Wall
	glColor3f(0.7, 0.2, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glVertex2f(3.00, 1.00);
	glVertex2f(1.00, 2.00);
	glEnd();

	// Front Wall Line
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.00, 4.50);
	glVertex2f(3.00, 3.50);
	glVertex2f(3.00, 1.00);
	glVertex2f(1.00, 2.00);
	glEnd();

	// window one
	glColor3f(0.2, 0.4, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(3.30, 3.20);
	glVertex2f(4.50, 3.20);
	glVertex2f(4.50, 2.30);
	glVertex2f(3.30, 2.30);
	glEnd();

	// line of window one
	glColor3f(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2f(3.30, 3.20);
	glVertex2f(4.50, 3.20);
	glVertex2f(4.50, 2.30);
	glVertex2f(3.30, 2.30);
	glEnd();

	// window two
	glColor3f(0.2, 0.4, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(5.30, 3.20);
	glVertex2f(6.50, 3.20);
	glVertex2f(6.50, 2.30);
	glVertex2f(5.30, 2.30);
	glEnd();

	// lines of window two
	glColor3f(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2f(5.30, 3.20);
	glVertex2f(6.50, 3.20);
	glVertex2f(6.50, 2.30);
	glVertex2f(5.30, 2.30);
	glEnd();

	//side Wall
	glColor3f(0.1, 0.2, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(3.00, 3.50);
	glVertex2f(7.00, 3.50);
	glVertex2f(7.00, 1.00);
	glVertex2f(3.00, 1.00);
	glEnd();

	//side wall line
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(3.00, 3.50);
	glVertex2f(7.00, 3.50);
	glVertex2f(7.00, 1.00);
	glVertex2f(3.00, 1.00);
	glEnd();
}

GLvoid road(){
	glRectd(-3.0,-0.87,3,-0.555);
}

GLvoid grass(){

		//********Background*************//
        glColor3f(0.0f,0.4f,0.1f);
    glTranslated(0,-0.1,0.999999);
    glRectd(-3.0,-0.5,3,0.38);
}

GLvoid bottomgrass(){
    glColor3f(0.0f,0.4f,0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(-3.0,-0.87);
    glVertex2f(3.0,-0.87);
    glVertex2f(-3.0,-1.0);
    glVertex2f(3.0,-1.0);
    glEnd();

    glBegin(GL_POLYGON);
		glVertex2f(-0.9,-0.87);
		glVertex2f(3.0,-0.87);
		glVertex2f(-0.9,-1.0);
		glVertex2f(3.0,-1.0);
        glEnd();
}

GLvoid range()
{
	glBegin(GL_POINTS);
	for(int i=0;i<500;++i)
		glVertex3f(cos(2*3.14159*i/100.0),sin(2*3.14159*i/100.0),0);
	glEnd();
}

GLvoid satellite(){
	//LINE WING
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(0.8, 0.5);
	glVertex2f(0.6, 0.53);
	glVertex2f(0.6,0.43);
	glEnd();
	glPopMatrix();

	//REST OF THE WING
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(0.60,0.53,0.0);
	glVertex3f(0.60,0.43,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0.80,0.50,0.0);
	glVertex3f(0.60,0.43,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0.6,0.43,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,1.0);
	glRectd(0.6,0.53,0.20,0.43);
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(0.4,0.5,0.0);
	glVertex3f(0.2,0.43,0.0);
	glVertex3f(0.60,0.43,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex3f(0.55,0.43,0.0);
	glVertex3f(0.55,0.53,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0.45,0.43,0.0);
	glVertex3f(0.45,0.53,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0.35,0.43,0.0);
	glVertex3f(0.35,0.53,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0.25,0.43,0.0);
	glVertex3f(0.25,0.53,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0.60,0.525,0.0);
	glVertex3f(0.20,0.525,0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0.60,0.475,0.0);
	glVertex3f(0.20,0.475,0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

}

GLvoid cube(){

	//CUBE
	glPushMatrix();
	glutSolidCube(0.2);
	glPopMatrix();

	glColor3f(0, 0, 0);
	glPushMatrix();
	glutWireCube(0.2);
	glPopMatrix();
}


GLvoid arrowhead1(){
	glBegin(GL_TRIANGLES);
	glVertex2f(0.3, 0.4);
	glVertex2f(0.5, 0.35);
	glVertex2f(0.3,0.3);
	glEnd();
}

GLvoid arrowhead2(){
	glBegin(GL_TRIANGLES);
	glVertex2f(0.4, 0.4);
	glVertex2f(0.25, 0.4);
	glVertex2f(0.25,0.3);
	glEnd();
}

GLvoid bus(){
	glTranslatef(-0.4,-1.05,0.0);
	glScaled(0.3,0.5,0.6);

	glBegin(GL_QUADS);                /* OBJECT MODULE*/

	//******************MIDDLE BODY************************************
	glColor3f(0.3,0.3,0.9);
	glVertex3f( 0.6, 0.5,0.6);
	glVertex3f(0.6, 0.2,0.6);
	glVertex3f(1.8, 0.2, 0.6);
	glVertex3f(1.8,0.5,0.6);

	/* bottom of cube*/
	glVertex3f( 0.6,0.2,0.6);
	glVertex3f(0.6,0.2,0.2);
	glVertex3f(1.8,0.2,0.2);
	glVertex3f( 1.8,0.2,0.6);

	/* back of cube.*/
	glVertex3f(0.6,0.5,0.2);
	glVertex3f(0.6,0.2,0.2);
	glVertex3f(1.8,0.2,0.2);
	glVertex3f(1.8,0.5,0.2);
	//*********************ENTER WINDOW**********************************
	glColor3f(0.3,0.3,0.3);
	glVertex3f( 0.77, 0.63,0.2);
	glVertex3f(0.75, 0.5,0.2);        //quad front window
	glVertex3f(1.2, 0.5, 0.2);
	glVertex3f(1.22,0.63,0.2);

	glVertex3f(1.2,0.63,.2);
	glVertex3f(1.2,0.5,0.2);        //quad back window
	glVertex3f(1.65,0.5,0.2);
	glVertex3f(1.6,0.63,0.2);

	glColor3f(0.3,0.3,0.9);
	glVertex3f(0.7,0.65,0.2);
	glVertex3f(0.7,0.5,.2);       //first separation
	glVertex3f(0.75,0.5,0.2);
	glVertex3f(0.77,0.65,0.2);

	glVertex3f(1.2,0.65,0.2);
	glVertex3f(1.2,0.5,.2);       //second separation
	glVertex3f(1.25,0.5,0.2);
	glVertex3f(1.27,0.65,0.2);

	glVertex3f(1.65,0.65,0.2);
	glVertex3f(1.65,0.5,.2);     //3d separation
	glVertex3f(1.7,0.5,0.2);
	glVertex3f(1.7,0.65,0.2);

	glVertex3f( 0.75, 0.65,0.2);
	glVertex3f(0.75, 0.63,0.2);        //line strip
	glVertex3f(1.7, 0.63, 0.2);
	glVertex3f( 1.7,0.65,0.2);

	glVertex3f( 0.75, 0.65,0.6);
	glVertex3f(0.75, 0.63,0.6);        //line strip
	glVertex3f(1.7, 0.63, 0.6);
	glVertex3f( 1.7,0.65,0.6);
	//**************************************************************
	glBegin(GL_QUADS);

	/* top of cube*/
	glClearColor(0.0,0.0,0.0,0.8);
	glColor3f(0.3,0.3,0.3);
	glVertex3f( 0.6, 0.5,0.6);
	glVertex3f( 0.7,0.65,0.6);       //tri front window
	glVertex3f(0.7,0.5,0.6);

	glVertex3f( 0.6, 0.5,0.2);
	glVertex3f( 0.7,0.65,0.2);       //tri front window
	glVertex3f(0.7,0.5,0.2);

	glVertex3f( 1.7, 0.65,0.2);
	glVertex3f( 1.8,0.5,0.2);       //tri back window
	glVertex3f( 1.7,0.5,0.2);
	glEnd();


	glColor3f(0.6,0.6,0.6);
	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+70)
	{
		glVertex3f(0.65,0.2,0.18);
		glVertex3f(0.65+(0.05*(cos(((theta+angle)*3.14)/180))),0.2+(0.05*(sin(((theta+angle)*3.14)/180))),0.18);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+70)
	{
		glVertex3f(1.74,0.2,0.18);
		glVertex3f(1.74+(0.05*(cos(((theta+angle)*3.14)/180))),0.2+(0.05*(sin(((theta+angle)*3.14)/180))),0.18);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+70)
	{
		glVertex3f(0.42,0.33,0.4);
		glVertex3f(0.42+(0.05*(cos(((theta+angle)*3.14)/180))),0.33+(0.05*(sin(((theta+angle)*3.14)/180))),0.4);
	}
	glEnd();

	//PRACTICE-------------------------
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+1)
	{
		glVertex3f(0.65,0.2,0.18);
		glVertex3f(0.65+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+1)
	{
		glVertex3f(1.74,0.2,0.2);
		glVertex3f(1.74+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.19);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for(theta=0;theta<360;theta=theta+1)
	{
		glVertex3f(0.42,0.33,0.4);
		glVertex3f(0.42+(0.08*(cos(((theta+angle)*3.14)/180))),0.33+(0.08*(sin(((theta+angle)*3.14)/180))),0.4);
	}
	glEnd();
	//----------------------------------

	glTranslated(0.015,0.05,0);
	glBegin(GL_QUADS);
	glColor3f(0.3,0.3,0.9);
	glVertex3f(1.71,0.58,0.2);
	glVertex3f(1.44,0.7,0.2);
	glVertex3f(0.7,0.58,0.2);
	glVertex3f(0.43,0.7,0.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(1.71,0.58,0.2);
	glVertex3f(1.44,0.7,0.2);
	glVertex3f(0.7,0.58,0.2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(0.35,0.58,0.2); //BOTTOM RIGHT
	glVertex3f(0.58,0.45,0.2); //TOP LEFT
	glVertex3f(0.7,0.58,0.2);  //BOTTOM RIGHT
	glVertex3f(0.45,0.7,0.2); //TOP LEFT
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3,0.3,0.9);
	glVertex3f(0.61,0.45,0.2); //TOP LEFT
	glVertex3f(0.35,0.579,0.2); //TOP LEFT
	glVertex3f(0.35,0.32,0.2);  //BOTTOM RIGHT
	glVertex3f(0.61,0.14,0.2); //BOTTOM RIGHT
	glEnd();

	glEnable(GL_DEPTH_TEST);

}


GLvoid earthStation(){
	//ANTENNA
	glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef (-0.8, 0.19, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.2,0.25);
	glVertex2f(0.27,0.3);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.27,0.3);
	glVertex2f(0.3,0.2);
	glEnd();

	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex3f(0.27,0.3,-0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.58, 0.24, 0.0);
	glColor3f(0.4,0.4,0.4);
	glRotated(70,-1.0,0,0);
	glScaled(0.08,0.08,0.08);
	glutSolidCone(0.7, 1.5, 4, 8);
	glEnd();
	glPopMatrix();

	//HEMISPHERE
	GLdouble eqn[4] = {1.0, 1.0, 0.0, 0.0};

	glColor3f (0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef (-0.55, 0.4, 0.0);
	glScaled(0.1,0.1,0.1);
	glRotatef(180.0,-1.0,0.5,-1.0);

	/*    clip lower half -- y < 0          */
	glClipPlane (GL_CLIP_PLANE0, eqn);
	glEnable (GL_CLIP_PLANE0);

	glutSolidSphere(1,16,16);
	glColor3f(1.0,1.0,1.0);
	glutWireSphere(1,16,16);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

}
float pkt=0,in=0,in1=0.35,in2=1,in3=0,in4=-0.35,in5=0,s2b=-0.75,s2b1=0.8,out=0.1;
int flag=0;
GLvoid carRange()
{
	glPushMatrix();
	glColor3f(1.0,1.0,0);

	if(xt>-2.2 && xt<-0.6)
	{
        glTranslated(-0.4,0.4,0);
		glRotated(40,0.4,0.4,0.2);
		glRectd(pkt,0,pkt+0.5,0.2);
		pkt+=0.2;
		if(pkt>=2.5){
			pkt=200;
			flag=1;
        }
	}
	else if(xt<=0.8 && xt>=-0.6)
	{
		glTranslated(-0.4,0.4,0);
		glRotated(60,0.4,0.4,0.2);
		glRectd(pkt,0,pkt+0.5,0.2);
		pkt+=0.2;
		if(pkt>=1.7){
			pkt=200;
			flag=1;
		}
	}
    else if(xt>0.8 && xt<1.6)
    {
        glTranslated(-0.4,0.4,0);
		glRotated(80,0.4,0.4,0.2);
		glRectd(pkt,0,pkt+0.5,0.2);
		pkt+=0.2;
		if(pkt>=1){
			pkt=200;
			flag=1;
		}
    }
     else if(xt>=1.6 && xt<2.0)
    {
        glTranslated(-0.4,0.4,0);
		glRotated(90,0.4,0.7,0.2);
		glRectd(pkt,0,pkt+0.5,0.2);
		pkt+=0.2;
		if(pkt>=1){
			pkt=200;
			flag=1;
		}
    }
	else if(xt>=2.0 && xt<3.0)
	{
		glTranslated(-0.4,0.4,0);
		glRotated(130,0.4,0.8,0);
		glRectd(pkt,0,pkt+0.5,0.2);
		pkt+=0.2;
		if(pkt>=1.4){
			pkt=200;
			flag=1;
		}
	}

    else if (xt>=3.0 && xt<3.8)
	{
		glTranslated(-0.4,0.4,0);
		glRotated(230,0.4,0.8,0);
		glRectd(pkt,0,pkt+0.5,0.2);
		pkt+=0.2;
		if(pkt>=1.7){
			pkt=200;
			flag=1;
		}
	}
	else if(xt<11.199994 && xt>5.199999)
	{
		glTranslated(-0.4,0.4,0);
		if(xt<=6.799998)
		{
			glRotated(60,xt-0.5,xt,-0.2);
			glRectd(pkt,0,pkt+0.8,0.2);
			pkt+=0.9;
			if(pkt>=4.2)
			{
				pkt=0;
			}
		}
		else if(xt>6.799998 &&xt<=7.799997)
		{
			glRotated(60,xt-0.5,xt,-0.2);
			glRectd(pkt,0,pkt+0.8,0.2);
			pkt+=0.4;
			if(pkt>=2.8)
			{
				pkt=0;
			}
		}
		else if(xt>7.799997 && xt<=8.99996)
		{
			glRotated(80,xt+0.4,xt,-0.2);
			glRectd(pkt,0,pkt+0.8,0.2);
			pkt+=0.4;
			if(pkt>=2.2)
			{
				pkt=0;
			}
		}
		else if(xt>8.999996 && xt<=9.199996)
		{
			glRotated(90,xt,xt-0.9,-0.2);
			glRectd(pkt,0,pkt+0.8,0.2);
			pkt+=0.4;
			if(pkt>=1.8)
			{
				pkt=0;
			}
		}
		else if(xt>9.199996 && xt<=9.59996){
			glRotated(100,xt,xt+0.6,-0.2);
			glRectd(pkt,0,pkt+0.8,0.2);
			pkt+=0.4;
			if(pkt>=1.4)
			{
				pkt=0;
			}
		}
		else if(xt>9.59996 && xt<=9.799995){
			glRotated(140,xt,xt+0.6,-0.2);
			glRectd(pkt,0,pkt+0.3,0.1);
			pkt+=0.4;
			if(pkt>=1.3)
			{
				pkt=0;
			}
		}

		else if(xt>9.799995 && xt<10.399995){
			glRotated(200,xt-2.2,xt+6.2,-0.5);
			glRectd(pkt,0,pkt+0.3,0.1);
			pkt+=0.4;
			if(pkt>=1.4)
			{
				pkt=0;
			}
		}
		else if(xt>10.399995 && xt<10.599995){
			glRotated(200,xt-2.2,xt+10.5,-0.5);
			glRectd(pkt,0,pkt+0.3,0.1);
			pkt+=0.4;
			if(pkt>=1.8)
			{
				pkt=0;
			}
		}
		else{
			glRotated(200,xt-2.2,xt+13.5,-0.5);
			glRectd(pkt,0,pkt+0.3,0.1);
			pkt+=0.4;
			if(pkt>=1.8)
			{
				pkt=0;
			}
		}
	}
	glPopMatrix();
}
int transfer=0;
GLvoid communication(void){
	//GSM1 to ES1
	glPushMatrix();
	glColor3f(1,1.0,0);
	if(xt<3.8 && xt>-2.2 && flag==1)
	{
		transfer=1;
	}

	if(transfer){
		flag=0;
		glTranslated(-0.4,0.1,0);
		glRotated(200,0.45,0.93,0);
		glRectd(in,0,in+0.1,-0.02);
		in+=0.04;
		if(in>=0.28){
			in=2;

			//ES1 to Satellite
			glTranslated(0.2,-0.2,0);
			glRotated(90,0.45,0.68,0);
			glRectd(in1,0,in1+0.1,0.02);
			in1+=0.04;
			if(in1>=1.2){

				in1=2;
				//Satellite to ES2
				glTranslated(1.1,-0.1,-0.9);
				glRotated(182,0.2,0.5,0.1);
				glRectd(in2,0,in2+0.1,-0.05);
				in2-=0.04;
				if(in2<=0.29){
					in2=-200;
					//ES2 to GSM2
					glTranslated(0.3,0,0);
					glRotated(10,0.1,0,0.2);
					glRectd(in3,0,in3+0.1,-0.05);
					in3-=0.04;
					if(in3<=-0.45){
						in3=-200;
						//GSM2 to House
						glTranslated(-0.55,-0.7,0);
						glRotated(160,-0.8,2,0.1);
						glRectd(in4,0,in4+0.1,-0.03);
						in4+=0.04;
						if(in4>=0){
							pkt=0;
							in=0;
							in1=0.35;
							in2=1;
							in3=0;
							in4=-0.35;
							transfer=0;
						}
					}
				}
			}
		}
	}
	glPopMatrix();
	glPushMatrix();
	//GSM2
	if(xt<11.199994 && xt>5.199999)
	{
        glTranslated(0.65,-0.2,0);
		glRotated(100,-0.5,1.6,0);
		glRectd(in5,0,in5+0.3,-0.02);
		in5+=0.1;
		if(in5>=0.7){
			in5=0;
		}
	}
	glPopMatrix();

	//Satellite to Bus
	glPushMatrix();
	glColor3f(0,0.8,1.0);
	glRotated(110,0.6,1,0);
	glRectd(s2b,0,s2b+0.1,-0.02);
	s2b+=0.2;
	if(s2b>=0.8){
		s2b=200;
		glTranslatef(-0.3,0,0);
		glRotated(100,0.6,0.3,0);
		glRectd(s2b1,0,s2b1+0.1,-0.02);
		s2b1-=0.2;
		if(s2b1<=-0.4){
			s2b=-0.75;
			s2b1=0.8;
		}
	}
	glPopMatrix();
}

GLvoid labels(void){

	glColor3f(0.0,0.0,0.0);
	glTranslated(0.63,-0.27,0);
	display_string(0.35,0.15,"GSM",3);
	glTranslated(-1,0,0);
	display_string(.35,.15,"GSM",3);
	glTranslated(-0.23,0.45,0);
	display_string(.35,.15,"Earth Station",3);
	glTranslated(0.98,-0.05,0);
	display_string(.35,.15,"Earth Station",3);
	glTranslated(-0.45,0.3,0);
	display_string(.35,.15,"Satellite",3);
	glTranslated(0.68,-1.3,0);
    display_string(.35,.15,"Destination",3);

}

void clouds(){
    glColor3f(3,3,3);
    glTranslated(-0.9,0.9,0);
    glScaled(0.08,0.08,1);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(-0.2,0.9,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(0.5,0.6,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(0.9,0.1,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(-1.9,-2.3,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(0.9,0.1,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(1.5,-0.5,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(0.9,-1.0,0);
    glTranslated(0,1.8,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(-0.2,1,0);
    glPushMatrix();
    glutSolidSphere(1,16,16);
    glPopMatrix();
    glTranslated(-1.4,-0.6,0);
    glScaled(2,2,1);
    glPushMatrix();
    glutSolidSphere(1,30,30);
    glPopMatrix();
}

int j=0;
GLvoid DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	/* Clear The Screen And The Depth Buffer */
	if(view==0)
	{
		init();
		display1();
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				//*********HOUSE***********//
		glPushMatrix();
		glTranslated(0.5,-0.9,0);
		glScaled(0.03,0.07,0.1);
		home();
		glPopMatrix();

		//***********BACKGROUND***********//
//		addImage();
		glPushMatrix();
		grass();
		glPopMatrix();

		glPushMatrix();
		bottomgrass();
		glPopMatrix();

        glPushMatrix();
        glTranslated(0.08,-0.2,0.999);
        //glScaled(0.5,1,1);
        clouds();
        glPopMatrix();

         glPushMatrix();
        glTranslated(0.5,-0.08,0.99999);
        //glScaled(0.5,1,1);
        clouds();
        glPopMatrix();

         glPushMatrix();
        glTranslated(1,-0.25,0.999);
        clouds();
        glPopMatrix();


        glPushMatrix();
        glTranslated(1.5,-0.09,0.999);
        clouds();
        glPopMatrix();

		//***********MOVE PACKETS********//
		glPushMatrix();
		communication();
		glPopMatrix();

		//*********LABELS**********//
		glPushMatrix();
		labels();
        glPopMatrix();

		//********RANGE FOR ES*********//
		glPushMatrix();
		glColor3f(0.0,1.0,0.0);
		glTranslated(0.45,-0.1,-0.3);
		glScaled(0.4,0.8,0.05);
		glPointSize(4.0);
		range();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.55,-0.1,-0.3);
		glScaled(0.4,0.8,0.05);
		range();
		glPopMatrix();

		//********GSM**********//
		glPushMatrix();
		glLineWidth(3.5);
		glColor3f(0.4,0.4,0.4);
		glTranslated(0.65,-0.2,0);
		glRotated(65, -1.0, 0.0, 0.0);
		glScaled(0.18,0.18,0.18);
		glutWireCone(0.4, 1.5, 4, 8);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.35,-0.2,0);
		glRotated(65, -1.0, 0.0, 0.0);
		glScaled(0.18,0.18,0.18);
		glutWireCone(0.4, 1.5, 4, 8);
		glPopMatrix();

		//********ARROWS*************//
		//Arrow from Satellite to ES2

		glPushMatrix();
		glColor3f(1,0,0);
		glTranslated(0.08,0.38,-0.09);
		glScaled(0.5,0.9,1);
		glRotated(-90,0.7,0.4,0.5);
		arrowhead1();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.05,0.47,-0.9);
		glScaled(0.5,0.89,1);
		glRotated(-90,0.7,0.4,0.5);
		glRectd(0.85, 0.38,0.1,0.32);
		glPopMatrix();

		//Arrow from ES1 to Satellite
		glPushMatrix();
		glTranslated(-0.435,0.68,-0.05);
		glScaled(0.5,0.6,1);
		glRotated(250,0.5,0.5,1);
		arrowhead1();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.468,0.62,-0.09);
		glScaled(0.65,0.55,1);
		glRotated(230,0.55,0.55,1);
		glRectd(0.85, 0.38,0.1,0.32);
		glPopMatrix();

		//Arrow from GSM1 to ES1
		glPushMatrix();
		glTranslated(-0.66,0.29,-0.05);
		glScaled(0.5,0.6,1);
		glRotated(250,0.5,0.5,1);
		arrowhead1();
		glPopMatrix();


		glPushMatrix();
		glTranslated(-0.68,0.05,-0.09);
		glScaled(0.5,0.89,1);
		glRotated(-90,0.5,0.5,0.5);
		glRectd(0.85, 0.38,0.1,0.32);
		glPopMatrix();

		//Arrow from ES to GSM2
		glPushMatrix();
		glTranslated(0.4,0,-0.09);
		glScaled(0.5,0.9,1);
		glRotated(-90,0.5,0.5,0.5);
		arrowhead1();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.32,0.11,-0.09);
		glScaled(0.5,0.89,1);
		glRotated(-90,0.5,0.5,0.5);
		glRectd(0.85, 0.38,0.1,0.32);
		glPopMatrix();

		//Arrow from GSM2 to House
		glPushMatrix();
		glTranslated(0.45,-0.28,-0.09);
		glScaled(0.5,0.8,1);
		glRotated(250,0.5,0.5,1);
		arrowhead1();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.468,-0.26,-0.09);
		glScaled(0.5,0.45,1);
		glRotated(250,0.55,0.55,1);
		glRectd(0.85, 0.38,0.1,0.32);
		glPopMatrix();

		//************ROADS********//
        glPushMatrix();
		glColor3f(0.1,0.1,0.1);
		glTranslated(0,0,0.99);
		road();
		glPopMatrix();
		//**********ROAD-STRIPES******//
        glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.2,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

        glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.3,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.4,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.5,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.7,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.8,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.9,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(0.1,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-0.3,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-0.4,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-0.5,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-0.6,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-0.7,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-0.8,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-0.9,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(-1.0,-0.66,0.98);
		glScaled(0.01,0.06,0.05);
		road();
		glPopMatrix();

    //*********BUS**************//
		glScaled(0.8,0.8,0.8);
		glPushMatrix();
		bus();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.28,-0.8,0);
		glScaled(0.5,0.5,0.5);
		glRotated(180,0,0.5,0);
		earthStation();
		glPopMatrix();

		//***********ES************//
		glPushMatrix();
		glRotated(180,0,0.5,0);
		glTranslated(1.2,0.052,0);
		earthStation();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.04,0,0);
		glRotated(180,0,0.5,0);
		earthStation();
		glPopMatrix();

		//********SATELLITE******//

		glTranslatef(-0.05,0.8,0.0);
		glScaled(0.6,1.2,1.2);
		glRotated(90.0,1,1.0,1);
		glPushMatrix();
		cube();
		glPopMatrix();

		//RIGHT WING
		glPushMatrix();
		glTranslated(-0.45,-0.3,0.3);
		glRotated(-90,-0.5,-0.5,1);
		glScaled(0.7,1,1);
		satellite();
		glPopMatrix();

		//LEFT WING
		glPushMatrix();
		glTranslated(0.8,-0.5,-0.68);
		glRotated(127,0.6,-0.65,1);
		glScaled(0.7,1.1,1);
		satellite();
		glPopMatrix();

		//********CAR*********//
		glPushMatrix();
		Car();
		carRange();
		glPopMatrix();
		glutSwapBuffers();
	}
}

void NormalKey(GLubyte key, GLint x, GLint y)
{
	switch ( key )    {
		case ESCAPE : printf("Escape pressed. Exit.\n");
			      glutDestroyWindow(window);	/* Close the window */
			      exit(0);
			      break;

		case ' ':view=1;
			 DrawGLScene();
			 break;
		default:break;
	}

}

static void SpecialKeyFunc( int Key, int x, int y )
{
	switch ( Key ) {
		case GLUT_KEY_RIGHT:
			xt += 0.2;
			printf("xt=%f\n", xt);
			break;

		case GLUT_KEY_LEFT:
			xt -= 0.2;
			printf("xt=%f\n", xt);
			break;
	}
}

void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void timer_callback(int a){
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer_callback,0);
}

//*************************** Main ***************************************************************

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(Xsize,Ysize);
	glutInitWindowPosition(0,0);

	glutCreateWindow("Mobile Satellite Communication");
	glutReshapeFunc(myreshape);
	glutDisplayFunc(DrawGLScene);
	glutTimerFunc(0,timer_callback,0);
	glutKeyboardFunc(NormalKey);
	glutSpecialFunc(SpecialKeyFunc);
	InitGL(Xsize,Ysize);
	glClearColor(0.3529,0.3525,0.3647,1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();
	return 1;
}
