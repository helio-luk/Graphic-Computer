/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116483 - Computação Gráfica 
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Aula: Mapeamento de textura
 * 
 * Funcao desse programa: apresentar recursos relacionados ao mapeamento de textura no OpenGL
 * 
 * Compilar: g++ text2d_base.cpp -lglut -lGLU -lGL `pkg-config --libs --cflags opencv` -o texture2D
 * Executar: ./texture2D
 */

#include<GL/glut.h>
#include<iostream>


#include <opencv/cv.h>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
GLubyte matrixTex[32][32][4];

Mat img = imread("grama.jpg");

void desenhaCena(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);    
    //glColor3f(1.0f,0.0f,0.0f);


    for(int i = 0; i<32;i++){
      for(int j = 0; j<32;j=j+2){
         matrixTex[i][j][0] = 255; 
         matrixTex[i][j][1] = 255;
         matrixTex[i][j][2] = 255;
         matrixTex[i][j][3] = 255;
      }
    }
   

    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA,img.cols,img.rows,0,GL_BGR,GL_UNSIGNED_BYTE, img.ptr());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0); glVertex2d(-0.5, 0.5);
        glTexCoord2f(0.0, 0.0); glVertex2d(-0.5, -0.5);
        glTexCoord2f(1.0, 0.0); glVertex2d(0.5, -0.5);
        glTexCoord2f(1.0, 1.0); glVertex2d(0.5, 0.5);
    glEnd();    

    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
    
    glFlush();

}

void idleFunc(){
     glutPostRedisplay();     
     glFlush();
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Textura 2D");
    glutDisplayFunc(desenhaCena);
    glutMainLoop();
    return 0;
}


