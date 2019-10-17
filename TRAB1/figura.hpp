#include <GL/glut.h>
#include <cmath>
#include <iostream>

class Figura{
	GLfloat v1_x, v1_y, v2_x, v2_y, v3_x, v3_y;
	public:
		void desenhaFigura(void);
};
void Figura::desenhaFigura(void){
	this->v1_x=0.2f;
	this->v1_y=0.2f;
	this->v2_x=0.4f;
	this->v2_y=0.2f;
	this->v3_x=0.3f;
	this->v3_y=0.4f;
	glColor3f(0.8f, 0.4f, 0.3f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(v1_x,v1_y);
		glVertex2f(v2_x,v2_y);
		glVertex2f(v3_x,v3_y);
	glEnd();
	glFlush();
}
