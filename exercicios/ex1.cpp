#include <GL/glut.h>
#include <cmath>
#define PI 3.1415926535

void Desenha(void){

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);



	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 1000; i++) {
		float angle = 2*PI*i/1000;
		glVertex2f(cos(angle), sin(angle));
	}


	glEnd();

	glFlush();
}

void Inicializa(void){

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
                   
	if(h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) 
		gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
	else 
	        gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);

}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,350);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Quadrado");
	glutDisplayFunc(Desenha);
	//glutReshapeFunc(AlteraTamanhoJanela);
	//Inicializa();
	glutMainLoop();
}
