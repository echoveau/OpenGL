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

  glPushMatrix();
  {
	glBegin(GL_QUADS);
	//face 1	
	glVertex3f(1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(1.0f,-1.0f,1.0f);

	//face 1 opposé
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,-1.0f,1.0f);

	//face 3
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);

	//face 3 opposé
	glVertex3f(1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,1.0f);
	glVertex3f(-1.0f,-1.0f,1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);





	glEnd();
  }
  glPopMatrix();

  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
