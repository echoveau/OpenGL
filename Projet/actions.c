#include "actions.h"
#include <stdio.h>

extern GLfloat xrot;   
extern GLfloat yrot; 
extern GLfloat z; 
extern int blend;
extern int light;
extern int helice_on;
extern GLfloat movement_aa;
extern GLfloat movement_dg;	
extern GLfloat movement_hb;
extern float vitesse_angulaire;	
extern float angle_avant;
extern float angle_droite;


void touche_pressee(unsigned char key, int x, int y) 
{
    switch (key) {    
    case ESCAPE: 
	exit(1);                   	
	break; 

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;

	//TOUCHE POUR DEMARRER LES HELICES
    case TOUCHE_MIN_O: 
      if(helice_on==0)      
		helice_on = 1;
      else
		helice_on = 0;
      break;
    
	//TOUCHES DE MOUVEMENT
    case TOUCHE_MIN_Z:
	if(vitesse_angulaire>1100 & movement_hb>1){	//movement_hb>1 pour ne pas faire du d/g a/a
		
		if(angle_avant>-30.0)
			angle_avant-=5;
		
		movement_aa=movement_aa+0.1;
	}	 					//avant que l'hélico ne soit décollé du sol
	   	
      break;

    case TOUCHE_MIN_Q:
	if(vitesse_angulaire>1100 & movement_hb>1){

		if(angle_droite>-45.0)
			angle_droite-=9;

		movement_dg=movement_dg-0.1;
	}
      break;

    case TOUCHE_MIN_S:
	if(vitesse_angulaire>1100 & movement_hb>1){
		if(angle_avant<20.0)
			angle_avant+=9;	

		movement_aa=movement_aa-0.1;
}
      break;

    case TOUCHE_MIN_D:
	if(vitesse_angulaire>1100 & movement_hb>1){
	
		if(angle_droite<45.0)
			angle_droite+=9;	

		movement_dg=movement_dg+0.1;
	}
		
      break;

    case TOUCHE_MIN_A:
	if(vitesse_angulaire>1100)
		movement_hb=movement_hb+0.1;
      break;

    case TOUCHE_MIN_E:
	if(movement_hb>0 & vitesse_angulaire>1100)		
		movement_hb=movement_hb-0.1;
      break;


    }
}


void touche_speciale(int key, int x, int y){

	switch (key){ 	
		case GLUT_KEY_PAGE_UP :
			z += 1.0f;
			break;

		case GLUT_KEY_PAGE_DOWN :
			z -= 1.0f;
			break;

		case GLUT_KEY_UP :
			xrot += 5.0f;			
			break;

		case GLUT_KEY_DOWN :
			xrot -= 5.0f;
			break;	
		
		case GLUT_KEY_LEFT :
			yrot += 5.0f;			
			break;

		case GLUT_KEY_RIGHT :
			yrot -= 5.0f;
			break;
	}

} 


























