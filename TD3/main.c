#include <GL/gl.h>
#include "init.h"
#include "axes.h"
#include "VM_init.h"


GLfloat xrot=0;
GLfloat yrot=0;
GLfloat z=0;


GLvoid Modelisation()
{
  VM_init();

  //glTranslatef(0.0f, 0.0f, -5.0f);

  glPushMatrix();
  {
	glBegin();



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
