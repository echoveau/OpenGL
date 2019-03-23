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

//Helico
float vitesse_angulaire=50.0;
int nb_frames=0;
int fps=0;
float vitesse_relative=0.0;
float acceleration_en_chute_libre=0.0;
int helice_on=0;
GLfloat movement_aa=0;		//avant/arrière
GLfloat movement_dg=0;		//droite/gauche
GLfloat movement_hb=0;		//haut/bas
float angle_avant=0;
float angle_droite=0;

//Helico Automatique
float vitesse_angulaire2=50.0;
float vitesse_relative2=0.0;
float acceleration_en_chute_libre2=0.0;
GLfloat movement_aa2=3.0;		//avant/arrière
GLfloat movement_dg2=-13.0;		//droite/gauche
GLfloat movement_hb2=0.0;		//haut/bas
int helice_on2=1;
float angle_avant2=0.0;
float angle_droite2=0.0;
GLfloat angle2=0.0f;

//Animation
int Anim_1=0;
int Anim_2=0;
int Anim_3=0;
int Anim_4=0;

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

float LightCouleur[4] = {0.5,0.5,0.5,0.5};
float LightPos[4] = {0.0, 10.0, 0.0, 100.0};


void animation(){
	if(vitesse_angulaire2>1250 & movement_hb2<15){
		movement_hb2+=0.1;
	  }
	  if(movement_hb2>14.5 & movement_aa2<10 & Anim_1==0){
			movement_aa2+=0.1;
			if(angle_avant2>-30.0)
				angle_avant2-=5;
			if(movement_aa2>9.8)
				Anim_1=1;
	  }
	  if(movement_aa2>3.0 & Anim_1==1){
		movement_aa2-=0.1;
		if(angle_avant2<20.0)
			angle_avant2+=9;
		if(movement_aa2<3.5)
			Anim_2=1;
	  }
	  if(Anim_1==1 & Anim_2==1){
		if(angle_avant2<0.0)
			angle_avant2-=5;	
		
		if(angle_droite2<45.0)
			angle_droite2+=9;	

		movement_dg2=movement_dg2+0.1;	

		if(movement_dg2>0){
			Anim_2=0;
			Anim_3=1;
		}	

	  }
	  if(Anim_3==1){
		if(angle_droite2>-45.0)
			angle_droite2-=9;

		movement_dg2=movement_dg2-0.1;
		if(movement_dg2<-13){
			Anim_3=0;
			Anim_4=1;		
		}
	  }
	  if(Anim_4==1){
		if(angle_droite2<0.0)
			angle_droite2+=5.0;
		if(angle_avant2>0.0)
			angle_avant2-=5;
		movement_dg2=-13.0;
		movement_aa2=3.0;
		if(angle_droite2>-1.0){
			angle_droite2=0.0;
			angle_avant2=0.0;
			helice_on2=0;
		}
	  }
}


GLvoid Modelisation()
{
  VM_init();

  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0,GL_POSITION,LightPos);
  glLightfv(GL_LIGHT0,GL_AMBIENT,LightCouleur);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,LightCouleur);
  glLightfv(GL_LIGHT0,GL_SPECULAR,LightCouleur);


  //SOL
  glPushMatrix();
  {	

	glTranslatef(0,-1.7,0);

	glBegin(GL_QUADS);
	glColor3f(0.0f,0.5f,0.0f);
	glVertex3f(100.0f,0.0f,100.0f);
	glVertex3f(100.0f,0.0f,-100.0f);
	glVertex3f(-100.0f,0.0f,-100.0f);
	glVertex3f(-100.0f,0.0f,100.0f);
	glEnd();


	
  }
  glPopMatrix();

   glPushMatrix();
     {
//VAISSEAU 1
  //Cockpit
	  glPushMatrix();
	  {
		glTranslatef(movement_aa,movement_hb,movement_dg);

		glRotatef(angle_droite,1,0,0);
		glRotatef(angle_avant,0,0,1);

		GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
		glColor3d(0.8,0.8,0.8);
		glScalef(5,3,3);

	    glutSolidSphere(0.5,100,5);
	
	  }
	  glPopMatrix();


	  //Pied1
	  glPushMatrix();
	  {
		glTranslatef(movement_aa,movement_hb,movement_dg);

		glRotatef(angle_droite,1,0,0);
		glRotatef(angle_avant,0,0,1);
	
		glTranslatef(0,-1.5,-0.6);

		GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
		glColor3d(0.8,0.8,0.8);
		glScalef(6,0.2,0.35);
			

	    glutSolidCube(0.5);
	
	
	  }
	  glPopMatrix();

	  //Pied2
	  glPushMatrix();
	  {
		glTranslatef(movement_aa,movement_hb,movement_dg);

		glRotatef(angle_droite,1,0,0);
		glRotatef(angle_avant,0,0,1);

		glTranslatef(0,-1.5,0.6);
		GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
		glColor3d(0.8,0.8,0.8);
		glScalef(6,0.2,0.35);		
	
	    glutSolidCube(0.5);
	
	  }
	  glPopMatrix();



	  //Jointure
	  glPushMatrix();
	  {
		glTranslatef(movement_aa,movement_hb,movement_dg);

		glRotatef(angle_droite,1,0,0);
		glRotatef(angle_avant,0,0,1);

		glTranslatef(0,1.6,0);

		glColor3d(0.8,0.8,0.8);
		glScalef(0.5,0.9,0.5);
	
	    glutSolidCube(0.5);
	
	  }
	  glPopMatrix();


	  //Hélice
	  glPushMatrix();
	  {
		glTranslatef(movement_aa,movement_hb,movement_dg);

		glRotatef(angle_droite,1,0,0);
		glRotatef(angle_avant,0,0,1);

		glRotatef(angle,0.0,1.0,0.0);
		glTranslatef(-0.25,2.0,0.0);	

		if(calcul_fps()&(fps!=0)&helice_on==1&vitesse_angulaire<1300){
			vitesse_relative=vitesse_angulaire/(float)fps;
			vitesse_angulaire+=50.0;
			acceleration_en_chute_libre=0;
			printf("%f \n",vitesse_angulaire);
		}

		if(helice_on==0 && vitesse_relative>0){
			vitesse_angulaire-=5;
			vitesse_relative=vitesse_angulaire/(float)fps;

			if(movement_hb>0){
				movement_hb-=acceleration_en_chute_libre;
				if(acceleration_en_chute_libre<=1)
					acceleration_en_chute_libre+=0.01;
			}
			if(movement_hb<0){
				movement_hb=0;
			}

			printf("%f \n",vitesse_angulaire);
		}


		angle += vitesse_relative;
	
		//Bouger l'oeil : yrot -= vitesse_relative;

		if(angle>=360.0) angle=0.0;

		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,5.0f);
		glVertex3f(0.5f,0.0f,5.0f);
		glVertex3f(0.5f,0.0f,0.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,-5.0f);
		glVertex3f(0.5f,0.0f,-5.0f);
		glVertex3f(0.5f,0.0f,0.0f);
		glEnd();

		glTranslatef(0.25,0.0,-0.25);
		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(5.0f,0.0f,0.0f);	
		glVertex3f(5.0f,0.0f,0.5f);
		glVertex3f(0.0f,0.0f,0.5f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(-5.0f,0.0f,0.0f);	
		glVertex3f(-5.0f,0.0f,0.5f);
		glVertex3f(0.0f,0.0f,0.5f);
		glEnd();
	  }
	  glPopMatrix();


	  //Queue
	  glPushMatrix();
	  {
		glTranslatef(movement_aa,movement_hb,movement_dg);

		glRotatef(angle_droite,1,0,0);
		glRotatef(angle_avant,0,0,1);

		glTranslatef(-2,0,0);
		glScalef(1,0.4,0.6);

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,2.0f,1.0f);
		glVertex3f(0.0f,2.0f,-1.0f);
		glVertex3f(0.0f,0.0f,-1.0f);
		glEnd();


		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(-5.0f,0.5f,0.5f);
		glVertex3f(-5.0f,1.5f,0.5f);
		glVertex3f(-5.0f,1.5f,-0.5f);
		glVertex3f(-5.0f,0.5f,-0.5f);
		glEnd();

	
		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(-5.0f,0.5f,0.5f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,-1.0f);
		glVertex3f(-5.0f,0.5f,-0.5f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,2.0f,1.0f);
		glVertex3f(-5.0f,1.5f,0.5f);
		glVertex3f(-5.0f,1.5f,-0.5f);
		glVertex3f(0.0f,2.0f,-1.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,2.0f,-1.0f);
		glVertex3f(0.0f,0.0f,-1.0f);
		glVertex3f(-5.0f,0.5f,-0.5f);
		glVertex3f(-5.0f,1.5f,-0.5f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,2.0f,1.0f);
		glVertex3f(-5.0f,1.5f,0.5f);
		glVertex3f(-5.0f,0.5f,0.5f);
		glEnd();

	  }
	  glPopMatrix();
    }
    glPopMatrix();


//VAISSEAU 2 (automatique)
  //Cockpit

   glPushMatrix();
     {
	  
	  if(vitesse_angulaire2==0){
		helice_on2=1;
		Anim_1=0;
		Anim_2=0;
		Anim_3=0;
		Anim_4=0;
	  }

	  animation();

	  //Hélice
	  glPushMatrix();
	  {
		glTranslatef(movement_aa2,movement_hb2,movement_dg2);

		glRotatef(angle_droite2,1,0,0);
		glRotatef(angle_avant2,0,0,1);

		glRotatef(angle2,0.0,1.0,0.0);
		glTranslatef(-0.25,2.0,0.0);	

		if(helice_on2==1 &vitesse_angulaire2<1300){
			vitesse_relative2=vitesse_angulaire2/(float)fps;
			vitesse_angulaire2+=1.0;
			acceleration_en_chute_libre2=0;
		}
		if(helice_on2==0 & vitesse_relative2>0){
			vitesse_angulaire2-=5;
			vitesse_relative2=vitesse_angulaire2/(float)fps;

			if(movement_hb2>0){
				movement_hb2-=acceleration_en_chute_libre2;
				if(acceleration_en_chute_libre2<=1)
					acceleration_en_chute_libre2+=0.01;
			}
			if(movement_hb2<0){
				movement_hb2=0;
			}
		}


		angle2 += vitesse_relative2;
		
	
		//Bouger l'oeil : yrot -= vitesse_relative;

		if(angle2>=360.0) angle2=0.0;

		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,5.0f);
		glVertex3f(0.5f,0.0f,5.0f);
		glVertex3f(0.5f,0.0f,0.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,-5.0f);
		glVertex3f(0.5f,0.0f,-5.0f);
		glVertex3f(0.5f,0.0f,0.0f);
		glEnd();

		glTranslatef(0.25,0.0,-0.25);
		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(5.0f,0.0f,0.0f);	
		glVertex3f(5.0f,0.0f,0.5f);
		glVertex3f(0.0f,0.0f,0.5f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(-5.0f,0.0f,0.0f);	
		glVertex3f(-5.0f,0.0f,0.5f);
		glVertex3f(0.0f,0.0f,0.5f);
		glEnd();
	  }
	  glPopMatrix();

	  
	  //Cockpit
	  glPushMatrix();
	  {
		glTranslatef(movement_aa2,movement_hb2,movement_dg2);

		glRotatef(angle_droite2,1,0,0);
		glRotatef(angle_avant2,0,0,1);

		GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
		glColor3d(0.8,0.8,0.8);
		glScalef(5,3,3);

	    glutSolidSphere(0.5,100,5);
	
	  }
	  glPopMatrix();


	  //Pied1
	  glPushMatrix();
	  {
		glTranslatef(movement_aa2,movement_hb2,movement_dg2);

		glRotatef(angle_droite2,1,0,0);
		glRotatef(angle_avant2,0,0,1);
	
		glTranslatef(0,-1.5,-0.6);

		GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
		glColor3d(0.8,0.8,0.8);
		glScalef(6,0.2,0.35);
			

	    glutSolidCube(0.5);
	
	
	  }
	  glPopMatrix();

	  //Pied2
	  glPushMatrix();
	  {
		glTranslatef(movement_aa2,movement_hb2,movement_dg2);

		glRotatef(angle_droite2,1,0,0);
		glRotatef(angle_avant2,0,0,1);

		glTranslatef(0,-1.5,0.6);
		GLfloat * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);
		glColor3d(0.8,0.8,0.8);
		glScalef(6,0.2,0.35);		
	
	    glutSolidCube(0.5);
	
	  }
	  glPopMatrix();



	  //Jointure
	  glPushMatrix();
	  {
		glTranslatef(movement_aa2,movement_hb2,movement_dg2);

		glRotatef(angle_droite2,1,0,0);
		glRotatef(angle_avant2,0,0,1);

		glTranslatef(0,1.6,0);

		glColor3d(0.8,0.8,0.8);
		glScalef(0.5,0.9,0.5);
	
	    glutSolidCube(0.5);
	
	  }
	  glPopMatrix();

	  

	  //Queue
	  glPushMatrix();
	  {
		glTranslatef(movement_aa2,movement_hb2,movement_dg2);

		glRotatef(angle_droite2,1,0,0);
		glRotatef(angle_avant2,0,0,1);

		glTranslatef(-2,0,0);
		glScalef(1,0.4,0.6);

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,2.0f,1.0f);
		glVertex3f(0.0f,2.0f,-1.0f);
		glVertex3f(0.0f,0.0f,-1.0f);
		glEnd();


		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(-5.0f,0.5f,0.5f);
		glVertex3f(-5.0f,1.5f,0.5f);
		glVertex3f(-5.0f,1.5f,-0.5f);
		glVertex3f(-5.0f,0.5f,-0.5f);
		glEnd();

	
		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(-5.0f,0.5f,0.5f);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,-1.0f);
		glVertex3f(-5.0f,0.5f,-0.5f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,2.0f,1.0f);
		glVertex3f(-5.0f,1.5f,0.5f);
		glVertex3f(-5.0f,1.5f,-0.5f);
		glVertex3f(0.0f,2.0f,-1.0f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,2.0f,-1.0f);
		glVertex3f(0.0f,0.0f,-1.0f);
		glVertex3f(-5.0f,0.5f,-0.5f);
		glVertex3f(-5.0f,1.5f,-0.5f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3d(0.8,0.8,0.8);
		glVertex3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,2.0f,1.0f);
		glVertex3f(-5.0f,1.5f,0.5f);
		glVertex3f(-5.0f,0.5f,0.5f);
		glEnd();

	  }
	  glPopMatrix();
   }
   glPopMatrix();

  axes();
  glutSwapBuffers();
}



int main(int argc, char **argv)
{
  return notre_init(argc, argv, &Modelisation);
}




















