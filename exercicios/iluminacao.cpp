#include <cmath>
#include<GL/glut.h>
#include<iostream>

using namespace std;

GLfloat theta = 0.0f;
GLfloat angle = 0.0f;
GLint p;
GLfloat i = -0.8f;
GLfloat j = -0.8f;
GLfloat k = 0.0f;

GLfloat r = 0.3f;

int aux = 0;

GLfloat posicao[] = {0.01f,0.0f,0.0f};

void projecaoPerspectiva(){

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(7.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    
    gluPerspective(45.0f,1.0f,1.0f,30.0f);
}


void globalLighting(){
    GLfloat global_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);	
    glEnable(GL_LIGHTING);

}

void lighting(){

    GLfloat white[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat red[] = {r, 0.0f, 0.0f, 1.0f};
 
    if(aux == 1){
    	posicao[0] = i;
    	posicao[1] = k;
    	posicao[2] = j;
    }

    glLightfv(GL_LIGHT0,GL_POSITION, posicao);
    glLightfv(GL_LIGHT0,GL_AMBIENT, black);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, red);
    glLightfv(GL_LIGHT0,GL_SPECULAR, white);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);



}

void lighting2(){

    GLfloat white[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat red[] = {0.3f, 0.0f, 0.0f, 1.0f};

    GLfloat green[] = {0.0f, 10.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0,GL_DIFFUSE, green);

  
    posicao[0] = -i;
    posicao[1] = -k;
    posicao[2] = -j;

    glLightfv(GL_LIGHT1,GL_POSITION, posicao);
    glLightfv(GL_LIGHT1,GL_AMBIENT, white);
    glLightfv(GL_LIGHT1,GL_DIFFUSE, red);
    glLightfv(GL_LIGHT1,GL_SPECULAR, white);
    glEnable(GL_LIGHT1);
}

void desenhaObjeto(){

    glPushMatrix();
    glRotatef(theta, 0.0f,0.0f, 1.0f);
    glutSolidTeapot(1.5f);    
    glPopMatrix();
}

void vagalume(){

    glPushMatrix();
    glTranslatef(i,k, j);
    glutSolidSphere(0.03f, 20.0f, 20.0f);    
    glPopMatrix();

}

void vagalume2(){

    glPushMatrix();
    glTranslatef(i+0.04,k+0.04, j+0.04);
    glutSolidSphere(0.03f, 20.0f, 20.0f);    
    glPopMatrix();

}

void desenhaCena(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    if(aux == 1){

    	lighting2();

	GLfloat ks2[] = {0.0f, 1.0f, 0.0f, 0.0f};
	//glMaterialfv(GL_FRONT,GL_EMISSION, ks2);

    	vagalume();
	//vagalume2();
    }

    lighting();
    desenhaObjeto();

    globalLighting();
    projecaoPerspectiva();
    glutSwapBuffers();
    glFlush();
	    
}

void keyboard(unsigned char key, int x, int y){
    if(key == '+')
	r = r + 0.3f;
    if(key == '-')
	r = r - 0.3f;
	if(r < 0.3f)
		r = 0.3f;
    if(key == 's')
	aux = 1;
		
}

void keyboard_special(int key, int x, int y){
    
}

void idleFunc(){    
     theta += 0.1f;     
     glutPostRedisplay();     
     glutSwapBuffers();
     glFlush();
     i = 1.9f*(cos(theta/2.2f)); 
     j = 1.9f*(sin(theta/2.2f));
     k = 0.1f*(cos(theta*7));
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Viewing 3D");
    glutKeyboardFunc(&keyboard);
    glutSpecialFunc(&keyboard_special);
    glutDisplayFunc(desenhaCena);
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}

