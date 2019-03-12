#include "actions.h"
#include <stdio.h>

extern GLfloat xrot;   
extern GLfloat yrot; 
extern GLfloat angler;
extern GLfloat anglea;
extern GLfloat anglez;
extern GLfloat anglee;
extern GLfloat anglet;
extern GLfloat anglet2;
extern blend;
extern light;

void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

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

    case TOUCHE_MIN_F: 
	if(angler<90)	      
		angler+=10;
	if(anglea<90)	
	      anglea+=10;
	if(anglez<90)	
	      anglez+=10;
	if(anglee<90)	      
		anglee+=10;
	if(anglet<90)	      
		anglet+=10; 
	if(anglet2<50)
		anglet2+=10;     
      break;

    case TOUCHE_MIN_O: 
      	if(angler>0)	
		angler-=10;
	if(anglea>0)	
		anglea-=10;
	if(anglez>0)	
		anglez-=10;
	if(anglee>0)	
		anglee-=10;
	if(anglet>0)	
		anglet-=10;
	if(anglet2>0)
		anglet2-=10;      
      break;

    case TOUCHE_MIN_R:
	if(angler<90)	
		angler+=10;
	break;
    case TOUCHE_MAJ_R:
	if(angler>0)	
		angler-=10;
	break;
	 
    case TOUCHE_MIN_A:
	if(anglea<90)	
		anglea+=10;
	break;
    case TOUCHE_MAJ_A:
	if(anglea>0)	
		anglea-=10;
	break;

    case TOUCHE_MIN_Z:
	if(anglez<90)	
		anglez+=10;
	break;
    case TOUCHE_MAJ_Z:
	if(anglez>0)	
		anglez-=10;
	break;

    case TOUCHE_MIN_E:
	if(anglee<90)
		anglee+=10;
	break;
    case TOUCHE_MAJ_E:
	if(anglee>0)	
		anglee-=10;
	break;

    case TOUCHE_MIN_T:
	if(anglet<90)
		anglet+=10;
	if(anglet2<50)
		anglet2+=10;
	break;
    case TOUCHE_MAJ_T:
	if(anglet>0)
		anglet-=10;
	if(anglet2>0)
		anglet2-=10;
	break;
    }	
}

