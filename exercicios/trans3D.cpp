#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <stdio.h>

GLfloat theta = 0.0f;
GLfloat t = -0.8f;

GLfloat k = 0.0f;



void animacao(){
	
	theta = theta + 0.3f;
	t = t + 0.0005f;	
	glutPostRedisplay();	
	if(t > 1.3f)
		t = -0.8f;
}

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);	

	glPushMatrix();	
	
	glColor3f(0.0f,1.0f,0.0f);


	glRotatef(theta, 1.0f, 0.0f, 0.0f);
	glTranslatef(t, k,0.0f);		
	glutWireSphere(0.5f, 20.0f,20.0f);	
	
	glPopMatrix();
	
	//glPushMatrix();

	glScalef(1.0f, 0.1f,1.0f);
	glTranslatef(0.0f,-5.3f,0.0f);		
	glutSolidCube(0.9f);
	
//	glPopMatrix();		
	glFlush();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(840,680);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Quadrado");
	glutDisplayFunc(Desenha);
	glutIdleFunc(animacao);
	glutMainLoop();
}
