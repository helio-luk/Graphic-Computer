/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116483 - Computação Gráfica 
 * Hélio Santana da Silva Júnior
 * 
 * Aula: Viewing 3D
 * 
 * Funcao desse programa: trabalhar com os diferentes tipos de projecoes
 *                    e posicionamento de cameras
 * 
 * Compilar: g++ viewing3D.cpp -lglut -lGLU -lGL -o view
 * Executar: ./view
 */

#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <stdio.h>

GLfloat theta = 0.0f;
GLfloat p = 2.0f;
GLfloat up = 3.0f;
GLfloat angle = 0.0f;
int mode=2;

void projecaoOrtogonal(){

    glEnable(GL_DEPTH_TEST);    
    glMatrixMode(GL_PROJECTION);      

    glLoadIdentity();    
    /* define as caracteristicas da projecao ortogonal
     1 xwmin
     2 xwmax
     3 ywmin
     4 ywmax
     5 dnear
     6 dfar
     */
    glOrtho(-5.0f,5.0f,-5.0f,5.0f,0.5f,10.0f);
    
}

void transfVisao2(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);    
    //glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    /* define a posicao da camera, para onde ela aponta, e a orientacao da camera */
    gluLookAt(7.0f, up, p, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    
    gluPerspective(45.0f,1.0f,1.0f,30.0f);

}

void transfVisao1(){
    glEnable(GL_DEPTH_TEST);    
    glMatrixMode(GL_PROJECTION);      

    glLoadIdentity();    
    /* define as caracteristicas da projecao ortogonal
     1 xwmin
     2 xwmax
     3 ywmin
     4 ywmax
     5 dnear
     6 dfar
     */
    glOrtho(-5.0f,5.0f,-5.0f,5.0f,0.5f,10.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(7.0f, up, p, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
}

void transfVisao3(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_MODELVIEW);    
    glLoadIdentity();
    
    //gluLookAt(5.0f, 3.0f, -3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    gluLookAt(7.0f, up, p, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    /* define uma projecao perspectiva obliqua
     * glFrustum(GLdouble xwmin, GLdouble xwmax,
     *           GLdouble ywmin, GLdouble ywmax,
                 GLdouble dnear, GLdouble dfar);
                 
                 (xwmin,ywmin) e (xwmax,ywmax) definem as coordenadas da janela de recorte
                 dnear e dfar definem as distancias da origem do sistema de coordenadas dos planos near/far ao longo do eixo zview

    */
    glFrustum(-2.0f,2.0f,-2.0f,2.0f,4.0f,18.0f);
}

void projecaoPerspectiva(){

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);    
    //glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    /* define a posicao da camera, para onde ela aponta, e a orientacao da camera */
    gluLookAt(7.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    
    gluPerspective(45.0f,1.0f,1.0f,30.0f);


}

void projecaoPerspectivaObliqua(){

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_MODELVIEW);    
    glLoadIdentity();
    
    //gluLookAt(5.0f, 3.0f, -3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    gluLookAt(7.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    /* define uma projecao perspectiva obliqua
     * glFrustum(GLdouble xwmin, GLdouble xwmax,
     *           GLdouble ywmin, GLdouble ywmax,
                 GLdouble dnear, GLdouble dfar);
                 
                 (xwmin,ywmin) e (xwmax,ywmax) definem as coordenadas da janela de recorte
                 dnear e dfar definem as distancias da origem do sistema de coordenadas dos planos near/far ao longo do eixo zview

    */
    glFrustum(-2.0f,2.0f,-2.0f,2.0f,4.0f,18.0f);
}

void Desenha(void){

    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f,0.0f,0.0f);
    
    glMatrixMode(GL_MODELVIEW);
    
    
    glPushMatrix();
    glTranslatef(2.5f,0.0f,0.0f);
    glutWireCube(1.5f);
    glPopMatrix();
    
    glPushMatrix();
    
    glTranslatef(-1.5f,0.0f,0.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    glRotatef(theta,0.0f,0.0f,1.0f);
	    
    glutWireSphere(1.0f,30,30);
    glPopMatrix();
    
    glFlush();
}

void keyboard_special(int key, int x, int y){
    if(key == GLUT_KEY_RIGHT){
        p=p+0.1;
	if(mode == 1)
		transfVisao1();
	if(mode == 2)
		transfVisao2();
	if(mode == 3)
		transfVisao3();
    }else{
        if(key == GLUT_KEY_LEFT){
            p = p-0.1;
	    if(mode == 1)
		transfVisao1();
	    if(mode == 2)
		transfVisao2();
	    if(mode == 3)
		transfVisao3();
        }else{
            if(key == GLUT_KEY_UP){
                angle=angle+0.05f;
		up = up+0.1f;
	        if(mode == 1)
	           transfVisao1();
		if(mode == 2)
		   transfVisao2();
		if(mode == 3)
	           transfVisao3();
            }else{
                if(key == GLUT_KEY_DOWN){
	            up = up-0.1f;
                    angle=angle-0.05f;
	        if(mode == 1)
	           transfVisao1();
		if(mode == 2)
		   transfVisao2();
		if(mode == 3)
	           transfVisao3();
                }
	    }
	}
    }
}

void keyboard(unsigned char key, int x, int y){
    if(key == 'l'){
        mode = 1;
	printf("Apertou paralela/ortogonal\n");
        projecaoOrtogonal();
    }
    if(key == 'o'){
        mode = 3;
	printf("Apertou obliqua\n");
        projecaoPerspectivaObliqua();
    }
    if(key == 'p'){
        mode = 2;
	printf("Apertou perspectiva\n");
        projecaoPerspectiva();
    }
}

void idleFunc(){
    
     theta += 0.01f;     
     glutPostRedisplay();     
     glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Viewing 3D");
	glutKeyboardFunc(&keyboard);
	glutSpecialFunc(&keyboard_special);
	glutDisplayFunc(Desenha);
	glutIdleFunc(idleFunc);
	glutMainLoop();
}
