#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <stdio.h>

GLfloat theta = 0.0f;
GLfloat t = -0.8f;
GLfloat k = -0.8f;

GLfloat t2 = 0.0f;
GLfloat k2 = 0.0f;

GLfloat t3 = 0.0f;
GLfloat k3 = 0.0f;

GLfloat t4 = 0.0f;
GLfloat k4 = 0.0f;

GLfloat t5 = 0.0f;
GLfloat k5 = 0.0f;

GLfloat t6 = 0.0f;
GLfloat k6 = 0.0f;

GLfloat t7 = 0.0f;
GLfloat k7 = 0.0f;

GLfloat t8 = 0.0f;
GLfloat k8 = 0.0f;

GLfloat w = 0.0f;
GLfloat i = 0.01f;
GLfloat i2 = 0.01f;
GLfloat i3 = 0.01f;
GLfloat i4 = 0.05f;
GLfloat i5 = 0.01f;
GLfloat i6 = 0.015f;
GLfloat i7 = 0.005f;
GLfloat i8 = 0.001f;


GLfloat eyeZ = 2.0f;
GLfloat eyeY = 2.0f;
GLfloat eyeX = 7.0f;

GLfloat upX = 0.0f;
GLfloat upY = 1.0f;
GLfloat upZ = 0.0f;

GLfloat centerX = 0.0f;
GLfloat centerY = 0.0f;
GLfloat centerZ = 0.0f;

int v1 = 1;
int b1 = 0;

void projecaoPerspectiva(){

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY,upZ);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,1.0f,1.0f,500.0f);
}

void keyboard(unsigned char key, int x, int y){
  if(key == 'v'){
    b1 = 0;
    v1 = 1;
  }
  if(key == 'b'){
    b1 = 1;
    v1 = 0;
  }
  if(v1 == 1){
      if(key == 'q'){
        eyeX = 7.0f;
        eyeY = 6.4f;
        eyeZ = 2.0f;
        centerX = 33.0f;
        centerY = 0.0f;
        centerZ = 0.0f;
        upX = 16.5;
        upY = 16.4;
        upZ =0.0f;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
      }
      if(key == 'w'){
          eyeX = 7.0f;
          eyeY = 230.8f;
          eyeZ = 2.0f;
          centerX = 0.0f;
          centerY = 0.0f;
          centerZ = 0.0f;
          upX = 0.0f;
          upY = 1.0;
          upZ =0.0f;
          printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
          projecaoPerspectiva();
      }
      if(key == 'e'){
          eyeX = 7.0f;
          eyeY = 187.9f;
          eyeZ = 179.1f;
          centerX = 7.69f;
          centerY = 11.0f;
          centerZ = -19.8f;
          upX = 114.39f;
          upY = 47.19;
          upZ =0.0f;
          printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
          projecaoPerspectiva();
      }
      if(key == 'r'){
          eyeX = 7.0f;
          eyeY = 82.29f;
          eyeZ = 3.1f;
          centerX = 8.8f;
          centerY = 0.0f;
          centerZ = 0.0f;
          upX = -54.99f;
          upY = -53.99;
          upZ =0.0f;
          printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
          projecaoPerspectiva();
      }
      if(key == 't'){
          eyeX = 7.0f;
          eyeY = 175.8f;
          eyeZ = -37.59f;
          centerX = 8.79f;
          centerY = -19.8f;
          centerZ = 0.0f;
          upX = -119.89f;
          upY = -40.79;
          upZ =0.0f;
          printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
          projecaoPerspectiva();
      }
      if(key == 'y'){
          eyeX = 7.0f;
          eyeY = 240.7f;
          eyeZ = -383.0f;
          centerX = -58.29f;
          centerY = 14.3f;
          centerZ = 0.0f;
          upX = 22.0f;
          upY = -40.79;
          upZ =0.0f;
          printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
          projecaoPerspectiva();
      }
  }
  if(b1 == 1){
    if(key == 'z'){
	      eyeX=eyeX+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'x'){
        eyeX=eyeX-1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'w'){
        upX=upX+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 's'){
        upX=upX-1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'd'){
        upY=upY+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 's'){
        upY=upY-1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'n'){
        upZ=upZ+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'm'){
        upZ=upZ-1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'i'){
        centerX=centerX+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'k'){
        centerX=centerX-1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'l'){
        centerY=centerY+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'j'){
        centerY=centerY-1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 'r'){
        centerZ=centerZ+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
    if(key == 't'){
        centerZ=centerZ-1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }
  }
}

void keyboard_special(int key, int x, int y){
    if(key == GLUT_KEY_RIGHT && b1 == 1){
        eyeZ=eyeZ+1.1;
        printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
        projecaoPerspectiva();
    }else{
        if(key == GLUT_KEY_LEFT && b1 == 1){
            eyeZ = eyeZ-1.1;
            printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
            projecaoPerspectiva();
        }else{
            if(key == GLUT_KEY_UP && b1 == 1){
		            eyeY = eyeY+1.1f;
                printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
                projecaoPerspectiva();
            }else{
                if(key == GLUT_KEY_DOWN && b1 == 1){
	                 eyeY = eyeY-1.1f;
                   printf("Para Modo de Posicionamento(TECLA V) da camera exigido no trabalho, apenas aperte as teclas de 'q' até 'y' PARA MODO LIVRE APERTE B: AS SETAS E AS TECLAS 'Z' E 'X' MOVIMENTAM O eye;  AS TECLAS WASD E NM MOVIMENTAM O center; AS TECLAS IJKL E RT MOVIMENTAM O up ");
                   projecaoPerspectiva();
                }
	    }
	}
    }

}

// Inicializa parâmetros de rendering
void Inicializa (void){

	glEnable(GL_LIGHTING);
		GLfloat light_position[] = { -4.0f, 3.0f, 1.0f, 0.0f };
		GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel (GL_SMOOTH);

	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 100.0f };

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

	glEnable(GL_NORMALIZE);
	glEnable(GL_POINT_SMOOTH);


	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glMaterialfv ( GL_FRONT_AND_BACK , GL_AMBIENT_AND_DIFFUSE , mat_diffuse );
	glEnable(GL_CULL_FACE);

	glClearColor(0, 0, 0, 0);

}


void animacao(){
	i = i + 0.1f;
	i2 = i2 + 0.01;
  i3 = i3 + 0.02f;
  i4 = i4 + 0.03;
  i5 = i5 + 0.04f;
  i6 = i6 + 0.05;
  i7 = i7 + 0.006f;
  i8 = i8 + 0.0007;

	theta = theta + 1.3f;

  t = 13.05f*(cos(i));
  k = 13.05f*(sin(i));

	t2 = 16.05f*(cos(i2));
	k2 = 16.05f*(sin(i2));

  t3 = 17.5f*(cos(i3));
	k3 = 17.5f*(sin(i3));

  t4 = 20.05f*(cos(i4));
  k4 = 20.05f*(sin(i4));

  t5 = 23.05f*(cos(i5));
  k5 = 23.05f*(sin(i5));

  t6 = 25.05f*(cos(i6));
  k6 = 25.05f*(sin(i6));

  t7 = 31.05f*(cos(i7));
  k7 = 31.05f*(sin(i7));

  t8 = 39.05f*(cos(i8));
  k8 = 39.05f*(sin(i8));

	glutPostRedisplay();


}

void sol(){
  glPushMatrix();
	glColor3f(1.0f,0.93f,0.0f);
	glRotatef(theta, 0.0f, 1.0f, 0.0f);
	glutSolidSphere(15.0f, 20.0f,20.0f);
	glRotatef(-theta, 0.0f, 1.0f, 0.0f);
	glPopMatrix();
}

void planeta1(){
  glPushMatrix();
	glColor3f(0.8f,1.0f,0.5f);
	glTranslatef(t, k,0.0f);
	glTranslatef(t, w,k);
	glRotatef(theta, 0.0f, 1.0f, 0.0f);
	glutSolidSphere(1.31f, 20.0f,20.0f);
	glRotatef(-theta, 0.0f, 1.0f, 0.0f);
	glPopMatrix();
}

void planeta2(){
  glPushMatrix();
  glColor3f(0.8f,1.0f,1.5f);
  glTranslatef(t2, k2,0.0f);
  glTranslatef(t2, w,k2);
  glRotatef(theta, 0.0f, 1.0f, 0.0f);
  glutSolidSphere(1.18f, 20.0f,20.0f);
  glRotatef(-theta, 0.0f, 1.0f, 0.0f);
  glPopMatrix();
}

void planeta3(){
  glPushMatrix();
  glColor3f(0.71f,0.57f,0.33f);
  glTranslatef(t3, k3,0.0f);
  glTranslatef(t3, w,k3);
  glRotatef(theta, 0.0f, 1.0f, 0.0f);
  glutSolidSphere(1.32f, 20.0f,20.0f);
  glRotatef(-theta, 0.0f, 1.0f, 0.0f);
  glPopMatrix();
}

void planeta4(){
  glPushMatrix();
  glColor3f(0.35f,0.36f,0.52f);
  glTranslatef(t4, k4,0.0f);
  glTranslatef(t4, w,k4);
  glRotatef(theta, 0.0f, 1.0f, 0.0f);
  glutSolidSphere(2.88f, 20.0f,20.0f);
  glRotatef(-theta, 0.0f, 1.0f, 0.0f);
  glPopMatrix();
}

void planeta5(){
  glPushMatrix();
  glColor3f(0.47f,0.50f,0.93f);
  glTranslatef(t5, k5,0.0f);
  glTranslatef(t5, w,k5);
  glRotatef(theta, 0.0f, 1.0f, 0.0f);
  glutSolidSphere(2.67f, 20.0f,20.0f);
  glRotatef(-theta, 0.0f, 1.0f, 0.0f);
  glPopMatrix();
}

void planeta6(){
  glPushMatrix();
  glColor3f(0.63f,0.54f,0.2f);
  glTranslatef(t6, k6,0.0f);
  glTranslatef(t6, w,k6);
  glRotatef(theta, 0.0f, 1.0f, 0.0f);
  glutSolidSphere(2.89f, 20.0f,20.0f);
  glRotatef(-theta, 0.0f, 1.0f, 0.0f);
  glPopMatrix();
}

void planeta7(){
  glPushMatrix();
  glColor3f(0.77f,0.74f,0.31f);
  glTranslatef(t7, k7,0.0f);
  glTranslatef(t7, w,k7);
  glRotatef(theta, 0.0f, 1.0f, 0.0f);
  glutSolidSphere(8.13f, 20.0f,20.0f);
  glRotatef(-theta, 0.0f, 1.0f, 0.0f);
  glPopMatrix();
}

void planeta8(){
  glPushMatrix();
  glColor3f(0.21f,0.69f,0.09f);
  glTranslatef(t8, k8,0.0f);
  glTranslatef(t8, w,k8);
  glRotatef(theta, 0.0f, 1.0f, 0.0f);
  glutSolidSphere(11.32f, 20.0f,20.0f);
  glRotatef(-theta, 0.0f, 1.0f, 0.0f);
  glPopMatrix();
}

void planetaTeste(){
  glPushMatrix();
  glutWireCube(1.5f);
  glPopMatrix();
}

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

  sol();
  planeta1();
  planeta2();
  planeta3();
  planeta4();
  planeta5();
  planeta6();
  planeta7();
  planeta8();

	glutSwapBuffers();

}


int main(int argc, char** argv){
  glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(40,10);
	glutCreateWindow("Quadrado");
	Inicializa();
	glutKeyboardFunc(&keyboard);
	glutSpecialFunc(&keyboard_special);
	glutDisplayFunc(Desenha);
	glutIdleFunc(animacao);
	glutMainLoop();
}
