#include <GL/glut.h>

GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;                                                    

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat windowWidth;
GLfloat windowHeight;

void Desenha(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
               glVertex2i(x1,y1+rsize); 
               glVertex2i(x1,y1);
               // Especifica que a cor corrente é azul
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(x1+rsize,y1);
               glVertex2i(x1+rsize,y1+rsize);               	
	glEnd();
	glutSwapBuffers();

}

void Timer(int value){

	if(x1 > windowWidth-rsize || x1 < 0)
		xstep = -xstep;

	if(y1 > windowHeight-rsize || y1 < 0)
		ystep = -ystep;

	if(x1 > windowWidth-rsize)
		x1 = windowWidth-rsize-1;

	if(y1 > windowHeight-rsize)
		y1 = windowHeight-rsize-1;

	x1 += xstep;
	y1 += ystep;

	glutPostRedisplay();
	glutTimerFunc(12,Timer, 1);
}

void Inicializa (void){   

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){

	if(h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)  {
		windowHeight = 250.0f*h/w;
		windowWidth = 250.0f;
	}else{ 
		windowWidth = 250.0f*w/h;
		windowHeight = 250.0f;
	}
     
	gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);

}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,350);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Anima");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutTimerFunc(12, Timer, 1);
	Inicializa();
	glutMainLoop();

}
