#include <stdio.h>     
#include <stdlib.h>     
#include <math.h>
#include <GL/gl.h>

GLfloat * mxm(GLfloat * m1, GLfloat * m2);

GLfloat * mxv(GLfloat * m, GLfloat * v);

void pretty_printer(GLfloat *m);

GLfloat * identite();

GLfloat * translation(GLfloat dx, GLfloat dy, GLfloat dz);

GLfloat * homothetie(GLfloat dx, GLfloat dy, GLfloat dz);

GLfloat * rotation(GLfloat x, GLfloat y, GLfloat z,GLfloat O);

GLfloat * cisaillement(GLfloat cxy, GLfloat cxz, GLfloat cyx,GLfloat cyz,GLfloat czx,GLfloat czy);
