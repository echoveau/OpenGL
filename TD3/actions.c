#include "actions.h"
#include <stdio.h>

extern GLfloat xrot;   
extern GLfloat yrot; 
extern GLfloat z; 
extern int blend;
extern int light;

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


























