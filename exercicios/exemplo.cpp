/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116483 - Computação Gráfica 
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Aula: Modelos de iluminacao
 * 
 * Funcao desse programa: apresentar as interacoes de iluminacao entre
 *                        objetos de uma cena
 * 
 * Compilar: g++ shading3D.cpp -lglut -lGLU -lGL -o shade
 * Executar: ./shade
 */

#include<GL/glut.h>
#include<iostream>

using namespace std;

GLfloat theta = 0.0f;
GLfloat p = 2.0f;
GLfloat angle = 0.0f;
int mode=2;

GLfloat position_type[] = {-4.0f, 4.0f, 4.0f };

/* Projecao perspectiva simetrica 
 utilizando gluPerspective */
void projecaoPerspectiva(){
    /* define a cor de fundo */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    /* habilita o teste de profundidade */
    glEnable(GL_DEPTH_TEST);
    
    /* define a matriz de transformacoes como a atual */
    glMatrixMode(GL_MODELVIEW);
    
    /* carrega a matriz identidade para a matriz atual */
    glLoadIdentity();
    
    /* define a posicao da camera, para onde ela aponta, e a orientacao da camera */
    gluLookAt(7.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f);
    
    /* define a matriz atual como a de projecao */
    glMatrixMode(GL_PROJECTION); 
    
    /* carrega a matriz identidade para a matriz atual */
    glLoadIdentity();
    
    /* define uma projecao perspectiva */
    gluPerspective(45.0f,1.0f,1.0f,30.0f);
}


void ambient_light(){
    
    GLfloat global_ambient[] = {0.9f, 0.9f, 0.9f, 1.0f};
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);

    glEnable(GL_LIGHTING);

}

void especular(){
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void lighting()
{

    GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};


    glLightfv(GL_LIGHT0, GL_POSITION, position_type);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,1.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,1.0);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION,1.0);
    
    ambient_light();
    
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
}


void desenhaCena(){

    /* Limpa o buffer e coloca a cor padrao de fundo */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    GLfloat ks[] = {0.1f, 0.1f, 0.1f, 0.25f};
    GLfloat kd[] = {0.6f,0.6f,0.6f,0.25f,};
    GLfloat ns = 128.0f;
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

//    glMaterialfv(GL_FRONT, GL_EMISSION, superficie);
    
    glMatrixMode(GL_MODELVIEW);
  
    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);
    glutSolidSphere(1.0f, 40, 40);
    glPopMatrix();
	
    GLfloat ks2[] = {0.5f, 0.5f, 0.5f, 0.5f};
    GLfloat kd2[] = {0.5f,0.5f,0.5f,0.5f,};
    GLfloat ns2 = 60.0f;
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks2);
    glMaterialf(GL_FRONT, GL_SHININESS, ns2);

//    glPushMatrix();
  //  glTranslatef(3.0f,0.0f, 0.0f);
 //   glutSolidSphere(1.0f, 40, 40);
//    glPopMatrix();

    glPushMatrix();
    glScalef(3.0f,0.1f,3.0f);
    glTranslatef(0.0f,-8.0f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();


    lighting();    
    projecaoPerspectiva();
    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    /*if(key == 'l')
    {
        mode = 1;
        cout <<"Apertou r\n";
        projecaoOrtogonal();
    }
    if(key == 'o')
    {
        mode = 3;
        cout <<"Apertou r\n";
    }
    if(key == 'p')
    {
        mode = 2;
        cout <<"Apertou r\n";*/
    //}
}

void keyboard_special(int key, int x, int y)
{
    if(key == GLUT_KEY_RIGHT)
    {
        p=p+0.1;
        cout<<"Para direita "<<p<<endl;
    }
    else
    {
        if(key == GLUT_KEY_LEFT)
        {
            p = p-0.1;
            cout<<"Para esquerda "<<p<<endl;
        }
        else
        {
            if(key == GLUT_KEY_UP)
            {
                angle=angle+0.05f;
                cout<<"Para cima "<<theta<<endl;
                
            }
            else
            {
                if(key == GLUT_KEY_DOWN)
                {
                    angle=angle-0.05f;
                    cout<<"Para baixo "<<theta<<endl;
                }
	    }
	}
    }
}

void reshapeFunc(int x, int y){
    if (y == 0 || x == 0) return;  
    projecaoPerspectiva();
}

void idleFunc(){
    
     theta += 0.01f;     
     glutPostRedisplay();     
     glFlush();
}



int main(int argc, char **argv){
    glutInit(&argc,argv);    
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);    
    glutInitWindowSize(500,500);    
    glutInitWindowPosition(100,100);    
    glutCreateWindow("Viewing 3D");    
    glutKeyboardFunc(&keyboard);    
    glutSpecialFunc(&keyboard_special);    
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);    
    glutDisplayFunc(desenhaCena);    
    glutIdleFunc(idleFunc);    
    glutMainLoop();
    
    return 0;
}

