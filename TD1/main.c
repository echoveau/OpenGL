// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test
// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o opmat.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "opmat.h"
#include <math.h>

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

/*
  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	
	
	glMultMatrixf(homothetie(1,10,1));

    glutSolidCube(0.1);
	
  }
  glPopMatrix();
*/

  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	
	glMultMatrixf(homothetie(1,5,1));
	glMultMatrixf(translation(0.3,0.3,0.3));
	

    glutSolidCube(0.1);
	
  }
  glPopMatrix();

  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
