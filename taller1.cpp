/*
Samir Valencia 1629607
Cristian Manosalva 1628397

Computacion Grafica, Universidad del Valle
Primer Taller.

a - activar/desactivar Ejes\n");
t - activar/desactivar tortuga de 2 dimensions
s - activar/desactivar tortuga de esferas
r - para cambiar el punto de vista

*/





#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#define length(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

GLfloat x0=0.0; 
GLfloat z0=0.0; 
GLfloat y0=2.0;
bool axisShow = true;
bool turtle =true;
bool turtle2 =true;
void drawSphereTurtle(){

  glColor3f(0.0, 0.0, 1.0);

  // body
  glPushMatrix();
  glTranslatef(0.0, 0.0, 0.10);
  glutWireSphere(0.35, 10, 10);
  glPopMatrix();

  // head
  glPushMatrix();
  glTranslatef(0.0, 0.0, 0.65);
  glutWireSphere(0.20, 15, 15);
  glPopMatrix();

  // legs
  glPushMatrix();
  glTranslatef(0.40, 0.0, 0.40);
  glutWireSphere(0.15, 15, 15);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.40, 0.0, 0.40);
  glutWireSphere(0.15, 15, 15);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.30, 0.0, -0.30);
  glutWireSphere(0.15, 15, 15);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.30, 0.0, -0.30);
  glutWireSphere(0.15, 15, 15);
  glPopMatrix();
}



void drawTurtle(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
    GLdouble x[]={
      0.00, 0.15, 0.20, 0.18, 0.10, 0.10,
      0.20, 0.20, 0.25, 0.37, 0.38, 0.36,
      0.27, 0.35, 0.35, 0.28, 0.42, 
      0.44, 0.36, 0.28, 0.23, 0.12, 0.00};
    GLdouble z[]={
      0.98, 0.90, 0.75, 0.65, 0.55, 0.45,
      0.40, 0.45, 0.50, 0.50, 0.45, 0.40,
      0.35, 0.20, 0.00, -0.20, -0.25,
      -0.35,-0.40, -0.35,-0.25,-0.20,-0.25};
    int npoints = length(x);


    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 1.0);
   for (int i = 0; i < npoints; i++)
   {
    glVertex3f(x[i],0.0,z[i]);
   }
   for (int i = npoints-1; i >= 0; i--)
   {
    glVertex3f(-x[i],0.0,z[i]);
   }
    glEnd();

}
void axis(void){
	//Eje X
    glColor3f(1.0,0.0,0.0);//es RGB asi que R para eje X
	glBegin(GL_LINES);
	glVertex3f(-10.0,0.0,0.0);
	glVertex3f(10.0,0.0,0.0);
	glEnd();
//Eje Y
    glColor3f(0.0,1.0,0.0);//es RGB asi que G para eje Y
	glBegin(GL_LINES);
	glVertex3f(0.0,-10.0,0.0);
	glVertex3f(0.0,10.0,0.0);
	glEnd();
//Eje Z
    glColor3f(0.0,0.0,1.0);//es RGB asi que B para eje Z
	glBegin(GL_LINES);
	glVertex3f(0.0,0.0,-10.0);
	glVertex3f(0.0,0.0,10.0);
	glEnd();
}

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

if(axisShow){
    	axis();
}else{}
if (turtle){
drawTurtle();	
	}
	else{}
if(turtle2){
	drawSphereTurtle();
}else{}


    glutSwapBuffers();
}
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'h':
        printf("help\n\n");
        printf("c - Toggle culling\n");

        printf("a - Toggle Axis\n");
        printf("t - Toggle turtle 2 dimensions\n");
        printf("s - Toggle Sphere Turtle\n");
        printf("r - change point of view\n");
 

        printf("1 - Rotate option 1\n");
        printf("2 - Rotate option 2\n");



        printf("q/escape - Quit\n\n");
        break;
    case 'c':
        if (glIsEnabled(GL_CULL_FACE))
           glDisable(GL_CULL_FACE);
        else
            glEnable(GL_CULL_FACE);
        break;
    case '1':
        glRotatef(1.0,1.,0.,0.);
        break;
    case '2':
        glRotatef(1.0,0.,1.,0.);
        break;
    case 'r':
    	x0+=0.01;
    gluLookAt(0.0, 0.0, 0.0, x0, y0, z0, 0.0, 0.001, 0.0);
    	break;
    case 'a':
    	axisShow=!axisShow;
    	break;
    case 't':
    	turtle=!turtle;
    	break;
    	case 's':
    	turtle2=!turtle2;
    	break;
    case 'q':
    case 27:
        exit(0);
        break;
    }
    drawTurtle();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("Taller1 CompuGrafica");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

	return 0;
}