#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "opmat.h"
#include <math.h>


GLfloat xrot=0;
GLfloat yrot=0;
GLfloat z=0;
GLfloat angle=0;
int temps;
int temps_cumule=0;
float vitesse_angulaire=45.0;
int nb_frames=0;
int fps=0;
float vitesse_relative=0.0;

int calcul_fps(){
	int temps_suivant=glutGet(GLUT_ELAPSED_TIME);
	int delta = temps_suivant-temps;
	temps = temps_suivant;
	temps_cumule += delta;
	nb_frames++;
	if(temps_cumule >= 1000){
		fps=nb_frames;
		
		temps_cumule=0;
		nb_frames=0;
		return 1;
	}
	return 0;
}


GLvoid Modelisation()
{
  VM_init();

  glPushMatrix();
  {
	glRotatef(angle,0.0,1.0,0.0);
	
	if(calcul_fps()&(fps!=0)){
		vitesse_relative=vitesse_angulaire/(float)fps;
	}

	printf("%i \n",fps);

	angle += vitesse_relative;
	
	//Bouger l'oeil : yrot -= vitesse_relative;

	if(angle>=360.0) angle=0.0;

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	glVertex3f(0.0f,1.0f,0.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
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




















