#include "init.h"

int window;
extern int blend=0;
extern int light=0;
extern temps=0;

GLvoid Redimensionne(GLsizei Width,GLsizei Height){
	glViewport(0,0,Width,Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat)Width/(GLfloat)Height ,0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}



int notre_init(int argc, char** argv, void (*DrawGLScene)()){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	window = glutCreateWindow("Test");

	glutDisplayFunc(DrawGLScene);
	glutIdleFunc(DrawGLScene);
	
	glutReshapeFunc(&Redimensionne);
	glutKeyboardFunc(&touche_pressee);
	glutSpecialFunc(&touche_speciale);
	
	glClearColor(0,0.5,1,1);
	glEnable(GL_DEPTH_TEST); 	
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	temps = glutGet(GLUT_ELAPSED_TIME);	

	glutMainLoop();

	return 1;
}

