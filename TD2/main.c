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
GLfloat angler=0;
GLfloat anglee=0;
GLfloat anglez=0;
GLfloat anglea=0;
GLfloat anglet=0;
GLfloat anglet2=0;

void phalange(GLfloat a,GLfloat b,GLfloat c){
glPushMatrix();
  {	
	glScalef(a,b,c);	
	glutSolidCube(0.5);
  }
  glPopMatrix();
}

GLvoid Modelisation()
{
  VM_init();

  //PAUME de la main:
  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	glColor3d(0.1,0.1,0.1);
	glScalef(5,0.4,2);
	
    glutSolidCube(0.5);
	
  }
  glPopMatrix();

  //INDEXE:
  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	glColor3d(1,1,0);

	glTranslatef(1.1,0,-0.4);
	glRotatef(angler,0,0,1);
	glTranslatef(0.5,0,0);
	phalange(1.25,0.4,0.4);			//phalange 1
			
	glTranslatef(0.30,0,0);	
	glRotatef(angler,0,0,1);	
	glTranslatef(0.30,0,0);	
	phalange(1.25,0.4,0.4);			//phalange 2


	glTranslatef(0.30,0,0);		
	glRotatef(angler,0,0,1);	
	glTranslatef(0.30,0,0);			
	phalange(1.25,0.4,0.4);			//phalange 3
	
  }
  glPopMatrix();


  //MAJEUR:
  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	glColor3d(0,0.5,0.5);

	glTranslatef(1.1,0,-0.1);		//phalange 1
    	glRotatef(anglee,0,0,1);
	glTranslatef(0.5,0,0);	
	phalange(1.65,0.4,0.4);

	glTranslatef(0.35,0,0);			//phalange 2
     	glRotatef(anglee,0,0,1);
	glTranslatef(0.35,0,0);	
	phalange(1.65,0.4,0.4);
	
	glTranslatef(0.35,0,0);			//phalange 3
     	glRotatef(anglee,0,0,1);
	glTranslatef(0.35,0,0);	
	phalange(1.65,0.4,0.4);
  }
  glPopMatrix();


  //ANNULAIRE:
  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	glColor3d(1,1,0);


	glTranslatef(1,0,0.2);		//phalange 1
    	glRotatef(anglez,0,0,1);
	glTranslatef(0.5,0,0);	
	phalange(1.3,0.4,0.4);

	glTranslatef(0.3,0,0);			//phalange 2
     	glRotatef(anglez,0,0,1);
	glTranslatef(0.3,0,0);	
	phalange(1.3,0.4,0.4);
	
	glTranslatef(0.3,0,0);			//phalange 3
     	glRotatef(anglez,0,0,1);
	glTranslatef(0.3,0,0);	
	phalange(1.3,0.4,0.4);
  }
  glPopMatrix();

  //RIKIKI:
  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	glColor3d(0,0.5,0.5);

	glTranslatef(1,0,0.5);		//phalange 1
    	glRotatef(anglea,0,0,1);
	glTranslatef(0.4,0,0);	
	phalange(0.8,0.4,0.4);

	glTranslatef(0.2,0,0);			//phalange 2
    	glRotatef(anglea,0,0,1);
	glTranslatef(0.2,0,0);
	phalange(0.8,0.4,0.4);
	
	glTranslatef(0.2,0,0);			//phalange 3
    	glRotatef(anglea,0,0,1);
	glTranslatef(0.2,0,0);		
	phalange(0.8,0.4,0.4);
  
  }
  glPopMatrix();

  //POUCE:
  glPushMatrix();
  {
	GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
	glColor3d(0.8,0,0);

	glTranslatef(-1.2,0.1,-0.55);		//phalange 1
    	glRotatef(anglet2,0,0,1);
	glTranslatef(0.6,0,0);		
	phalange(2,0.4,0.8);

	glTranslatef(0.4,0,0);			//phalange 2
    	glRotatef(anglet,0,-1,0);
	glTranslatef(0.4,0,0);		
	phalange(1.6,0.4,0.4);

	glTranslatef(0.375,0,0);			//phalange 3
    	glRotatef(anglet,0,-1,0);
	glTranslatef(0.375,0,0);		
	phalange(1.5,0.4,0.4);
  }
  glPopMatrix();

  axes();
  glutSwapBuffers();
}



int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}



/*

	glScalef(1,5,1);					Homotéthie
	glTranslatef(0.3,0.3,0.3);				Translation
	glRotatef(0.1,1,1,1);					Rotation
*/
