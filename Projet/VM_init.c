#include "VM_init.h"

extern GLfloat xrot,yrot;
extern GLfloat z;

void VM_init(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//L'oeil
	//glTranslatef(0.0f, 0.0f, 5.0f);
	glTranslatef(0.0,0.0,z);
	glRotatef(xrot,1.0,0.0,0.0);
	glRotatef(yrot,0.0,1.0,0.0);

}
