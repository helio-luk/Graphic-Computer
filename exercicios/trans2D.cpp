#include <GL/glut.h>
#include <cmath>
#include <iostream>
#define PI 3.1415926535

class Triangulo{
	GLfloat v1_x, v1_y, v2_x, v2_y, v3_x, v3_y;
	public:
		void desenhaTriangulo(void);
};


void Triangulo::desenhaTriangulo(void){

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

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

class Retangulo{
	GLfloat v1_x, v1_y, v2_x, v2_y,v3_x, v3_y, v4_x, v4_y;
	public:
		void desenhaRetangulo(void);
};


void Retangulo::desenhaRetangulo(void){

//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();


	this->v1_x=0.5f;
	this->v1_y=0.5f;
	this->v2_x=0.7f;	
	this->v2_y=0.5f;
	this->v3_x=0.7f;
	this->v3_y=0.7f;
	this->v4_x=0.5f;	
	this->v4_y=0.7f;
	glColor3f(0.9f, 0.2f, 0.7f);
	glBegin(GL_QUADS);
		glVertex2f(v1_x,v1_y);
		glVertex2f(v2_x,v2_y);
		glVertex2f(v3_x,v3_y);
		glVertex2f(v4_x,v4_y);
	glEnd();
	glFlush();
}

void translacao2D(GLfloat tx, GLfloat ty){

	glMatrixMode(GL_MODELVIEW);
	
	//glLoadIdentity();

	glTranslatef(tx, ty, 0.0f);

}

void rotacao2D(GLfloat angulo){
	GLfloat cx, cy;
	
	cx = (0.5f + 0.5f + 0.7f + 0.7f) /4.0f;
	cy = (0.5f + 0.7f + 0.7f + 0.5f) /4.0f;

	glTranslatef(cx, cy, 0.0f);

	glRotatef(angulo, 0.0f,0.0f,0.1f);

	glTranslatef(-cx, -cy, 0.0f);

}

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);

	Triangulo tri;
	tri.desenhaTriangulo();

	Retangulo rect;
	rect.desenhaRetangulo();
	
//	translacao2D(-0.9f,0.0f);
//	rotacao2D(30.0f);

}

void Inicializa(void){

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
                   
	if(h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	if (w <= h) 
		gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
	else 
	        gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);

}

void keyboard_special(int key, int x, int y){

	if(GLUT_KEY_UP == key){		
		std::cout << "Para cima !!\n";
		translacao2D(0.0f,0.1f);
	}
	if(GLUT_KEY_DOWN == key){
		std::cout << "Para baixo !!\n";
		translacao2D(0.0f,-0.1f);
	}
	if(GLUT_KEY_LEFT == key){
		std::cout << "Para esquerda !!\n";
		translacao2D(-0.1f,0.0f);
	}
	if(GLUT_KEY_RIGHT == key){
		std::cout << "Para direita !!\n";
		translacao2D(0.1f,0.0f);
	}

	glutDisplayFunc(Desenha);
	glutPostRedisplay();
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

	glutSpecialFunc(&keyboard_special);
	glutMainLoop();
}
