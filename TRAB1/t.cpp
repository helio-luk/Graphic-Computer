#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "figura.hpp"
#include <stdio.h>

char a;

void escala(GLfloat w, GLfloat h) {
  GLfloat cx, cy;
  cx = (0.2f + 0.4f + 0.3f) /3.0f;
  cy = (0.2f + 0.2f + 0.4f) /3.0f;
  glTranslatef(cx, cy, 0.0f);
  glScalef(w,h,0.0f);
  glTranslatef(-cx, -cy, 0.0f);
}

void translacao2D(GLfloat tx, GLfloat ty){
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(tx, ty, 0.0f);
}

void rotacao2D(GLfloat angulo){
	GLfloat cx, cy;
	cx = (0.2f + 0.4f + 0.3f) /3.0f;
	cy = (0.2f + 0.2f + 0.4f) /3.0f;
	glTranslatef(cx, cy, 0.0f);
	glRotatef(angulo, 0.0f,0.0f,0.1f);
	glTranslatef(-cx, -cy, 0.0f);
}

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);
	Figura tri;
	tri.desenhaFigura();
}

void keyboard_normal(unsigned char key, int x, int y){
  if(key == 't')
    a = 't';
  if(key == 's')
    a = 's';
  if(key == 'r')
    a = 'r';
}

void keyboard_special(int key, int x, int y){
  switch (a) {
    case 't':
      if(GLUT_KEY_UP == key){
        std::cout << "Para cima !!\n";
        translacao2D(0.0f,0.1f);
      }else if(GLUT_KEY_DOWN == key){
        std::cout << "Para baixo !!\n";
        translacao2D(0.0f,-0.1f);
      }else if(GLUT_KEY_LEFT == key){
        std::cout << "Para esquerda !!\n";
        translacao2D(-0.1f,0.0f);
      }else if(GLUT_KEY_RIGHT == key){
        std::cout << "Para direita !!\n";
        translacao2D(0.1f,0.0f);
      }else{
        glutKeyboardFunc(&keyboard_normal);
      }
      break;
    case 'r':
      if(GLUT_KEY_UP == key){
        std::cout << "ANTI HORARIO !!\n";
        rotacao2D(1.0f);
      }else if(GLUT_KEY_DOWN == key){
        std::cout << "HORARIO !!\n";
        rotacao2D(-1.0f);
      }else{
        glutKeyboardFunc(&keyboard_normal);
      }
      break;
    case 's':
      if(GLUT_KEY_UP == key){
        std::cout << "CRESCE !!\n";
        escala(2.0f, 2.0f);
      }else if(GLUT_KEY_DOWN == key){
        std::cout << "DIMINUI !!\n";
        escala(0.5f, 0.5f);
      }else{
        glutKeyboardFunc(&keyboard_normal);
      }
      break;
  }
	glutDisplayFunc(Desenha);
	glutPostRedisplay();
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(840,680);
	glutInitWindowPosition(0.0f,0.0f);
	glutCreateWindow("Figura");
	glutDisplayFunc(Desenha);
  printf("Digite 's' para escala, 'r' para rotacao ou 't' para translacao\n");
  glutKeyboardFunc(&keyboard_normal);
  glutSpecialFunc(&keyboard_special);
	glutMainLoop();
}
