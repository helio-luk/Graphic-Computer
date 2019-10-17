#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "bitmap.h"
#include "City.hpp"
#include "shader_utils.hpp"
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

#define PI 3.1415926

int          City::m_pos_attribute_location;
unsigned int City::m_vertexbuffer;
unsigned int City::m_frame;
unsigned int City::m_program;
unsigned int City::m_vertexsh;
unsigned int City::m_fragmentsh;
int          City::x0         = 0;
int          City::y0         = 0;
int          City::camera     = 0;
float        City::rotx       = 0;
float        City::roty       = 0;
float        City::rotz       = 0;
float        City::cposx      = 0;
float        City::cposy      = 0;
float        City::cposz      = 3;
float        City::up         = 0.25;
float        City::zoom       = 10;
float        City::walk_speed = 0.1;
static int   degree           = 20;
static float t;

static unsigned int m_texture;
static unsigned int street_texture;
static unsigned int car_texture;
static unsigned int structure_texture;
static unsigned int skybox_texture;
static unsigned int wall_texture;
static unsigned int house_texture;
static unsigned int grass_texture;

City::City(int argc, char** argv){
  m_frame = 0;
  glutInitWindowSize(City::m_width, City::m_height);
  glutInit(&argc,argv);
  glutInitDisplayString("samples rgb double depth");
  glutCreateWindow("City");
  glutMouseFunc(mouseHandler);
  glutKeyboardFunc(keyDown);
  //glutKeyboardUpFunc(keyUp);
  //glutSpecialFunc(specialKeyDown);
  glutSpecialFunc(specialKeyUp);
  glutMotionFunc(mouseMove);
  glutDisplayFunc(render);         //desenha
  glutIdleFunc(update);            //animacao da cena
  initOpenGL();
}

void City::checkExtensions(){

  if(glewGetExtension("GL_ARB_shading_language_100") != GL_TRUE)
      std::cout << "ERROR: Shading language extension not present." << std::endl;

  if(glewGetExtension("GL_ARB_vertex_program") != GL_TRUE)
      std::cout << "ERROR: Vertex program extension not present." << std::endl;

  if(glewGetExtension("GL_ARB_vertex_shader") != GL_TRUE)
      std::cout << "ERROR: Vertex shader extension not present." << std::endl;

  if(glewGetExtension("GL_ARB_fragment_program") != GL_TRUE)
      std::cout << "ERROR: Fragment program extension not present." << std::endl;

  if(glewGetExtension("GL_ARB_fragment_shader") != GL_TRUE)
      std::cout << "ERROR: Fragment shader extension not present." << std::endl;

  if(glewGetExtension("GL_ARB_vertex_buffer_object") != GL_TRUE)
      std::cout << "ERROR: VBO extension not present." << std::endl;

}

void City::initOpenGL(){
  glewExperimental = GL_TRUE;
  GLenum err = glewInit();

  if(err != GLEW_OK){
      std::cout << "ERROR: Loading GLEW failed." << std::endl;
      exit(-1);
  }

  checkExtensions();

  glClearColor(1, 1, 1, 0);
  glEnable(GL_DEPTH_TEST);

  CBitmap skybox("bitmap/skybox.bmp");
  glGenTextures(1, &m_texture);
  glUniform1i(skybox_texture, 0);
  glBindTexture(GL_TEXTURE_2D, skybox_texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, skybox.GetWidth(), skybox.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, skybox.GetBits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  glBindTexture(GL_TEXTURE_2D, 0);

  CBitmap streets("bitmap/streets.bmp");
  glGenTextures(1, &street_texture);
  glUniform1i(street_texture, 0);
  glBindTexture(GL_TEXTURE_2D, street_texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, streets.GetWidth(), streets.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, streets.GetBits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glBindTexture(GL_TEXTURE_2D, 0);

  CBitmap car("bitmap/car.bmp");
  glGenTextures(1, &car_texture);
  glUniform1i(car_texture, 0);
  glBindTexture(GL_TEXTURE_2D, car_texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, car.GetWidth(), car.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, car.GetBits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glBindTexture(GL_TEXTURE_2D, 0);

  CBitmap structure("bitmap/structure.bmp");
  glGenTextures(1, &structure_texture);
  glUniform1i(structure_texture, 0);
  glBindTexture(GL_TEXTURE_2D, structure_texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, structure.GetWidth(), structure.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, structure.GetBits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glBindTexture(GL_TEXTURE_2D, 0);

  CBitmap house("bitmap/house.bmp");
  glGenTextures(1, &house_texture);
  glUniform1i(house_texture, 0);
  glBindTexture(GL_TEXTURE_2D, house_texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, house.GetWidth(), house.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, house.GetBits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  glBindTexture(GL_TEXTURE_2D, 0);

  CBitmap grass("bitmap/grass.bmp");
  glGenTextures(1, &grass_texture);
  glUniform1i(grass_texture, 0);
  glBindTexture(GL_TEXTURE_2D, grass_texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, grass.GetWidth(), grass.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, grass.GetBits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  glBindTexture(GL_TEXTURE_2D, 0);

  CBitmap wall("bitmap/wall.bmp");
  glGenTextures(1, &wall_texture);
  glUniform1i(wall_texture, 0);
  glBindTexture(GL_TEXTURE_2D, wall_texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, wall.GetWidth(), wall.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, wall.GetBits());

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glBindTexture(GL_TEXTURE_2D, 0);

  makeShaders();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60,(float)m_width/(float)m_height,0.1,1000);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_CULL_FACE);

}

void City::render(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  GLfloat white[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};
  GLfloat red[] = {0.5, 0.0f, 0.0f, 1.0f};

  GLfloat posicao[] = {10.0f,0.0f,0.0f};

  glLightfv(GL_LIGHT0,GL_POSITION, posicao);
  glLightfv(GL_LIGHT0,GL_AMBIENT, black);
  glLightfv(GL_LIGHT0,GL_DIFFUSE, red);
  glLightfv(GL_LIGHT0,GL_SPECULAR, white);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);


  float t  = (float) ((int) (((float) clock()) * 50.0 / CLOCKS_PER_SEC) % 30) / 30.0;
  int   t2 = ((int) (((float) clock()) * 50.0 / CLOCKS_PER_SEC) % 240) / 30;
  float t3 = (float) clock() * 5.0 / CLOCKS_PER_SEC;

  GLfloat curves[8][4][3] =
  {
      {
          {-8, 0, -8.5},
          {-7, 0, -8.5},
          {-5, 0, -8.5},
          {-4, 0, -8.5}
      },
      {
          {-4, 0, -8.5},
          {-3.5, 0, -8.5},
          {-3.5, 0, -8.5},
          {-3.5, 0, -8}
      },
      {
          {-3.5, 0, -8},
          {-3.5, 0, -7},
          {-3.5, 0, -5},
          {-3.5, 0, -4}
      },
      {
          {-3.5, 0, -4},
          {-3.5, 0, -3.5},
          {-3.5, 0, -3.5},
          {-4, 0, -3.5}
      },
      {
          {-4, 0, -3.5},
          {-5, 0, -3.5},
          {-7, 0, -3.5},
          {-8, 0, -3.5}
      },
      {
          {-8, 0, -3.5},
          {-8.5, 0, -3.5},
          {-8.5, 0, -3.5},
          {-8.5, 0, -4}
      },
      {
          {-8.5, 0, -4},
          {-8.5, 0, -5},
          {-8.5, 0, -7},
          {-8.5, 0, -8}
      },
      {
          {-8.5, 0, -8},
          {-8.5, 0, -8.5},
          {-8.5, 0, -8.5},
          {-8, 0, -8.5}
      }
  };

  float s = 1 - t;
  float AB[2] = {curves[t2][0][0]*s + curves[t2][1][0]*t, curves[t2][0][2]*s + curves[t2][1][2]*t};
  float BC[2] = {curves[t2][1][0]*s + curves[t2][2][0]*t, curves[t2][1][2]*s + curves[t2][2][2]*t};
  float CD[2] = {curves[t2][2][0]*s + curves[t2][3][0]*t, curves[t2][2][2]*s + curves[t2][3][2]*t};
  float ABC[2] = {AB[0]*s + BC[0]*t, AB[1]*s + BC[1]*t};
  float BCD[2] = {BC[0]*s + CD[0]*t, BC[1]*s + CD[1]*t};
  float pos[2] = {ABC[0]*s + BCD[0]*t, ABC[1]*s + BCD[1]*t};
  float slope = (ABC[1] - BCD[1]) / (ABC[0] - BCD[0]);
  float theta = atan(slope);

  float matrix[4][4] =
  {
      {cos(theta), 0, -sin(theta), 0},
      {0, 1, 0, 0},
      {sin(theta), 0, cos(theta), 0},
      {pos[0], 0.01, pos[1], 1}
  };

  if((ABC[0] - BCD[0]) < 0){
      matrix[0][2] = -(matrix[0][2]);
      matrix[2][0] = -(matrix[2][0]);
  }else if((ABC[0] - BCD[0]) > 0){
      matrix[0][0] = -(matrix[0][0]);
      matrix[2][2] = -(matrix[2][2]);
  }



  //Draw streets

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, street_texture);
  glUseProgram(m_program);
  glBegin(GL_TRIANGLE_STRIP);

  glTexCoord2f(0,3);
  glNormal3f(0,1,0);
  glVertex3f(-10,0,-10);

  glTexCoord2f(0,0);
  glNormal3f(0,1,0);
  glVertex3f(-10,0,10);

  glTexCoord2f(3,3);
  glNormal3f(0,1,0);
  glVertex3f(10,0,-10);

  glTexCoord2f(3,0);
  glNormal3f(0,1,0);
  glVertex3f(10,0,10);

  glEnd();
  glUseProgram(0);
  glDisable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);

  //

  //Draw grass
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 13; j++){
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glTranslatef(15.5-(i),0,-3.5+(j));
      //glRotatef(90.0, 1.0, 0.0, 0.0);
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, grass_texture);
      glUseProgram(m_program);
      drawGrass();
      glEnd();

      glUseProgram(0);
      glDisable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, 0);
      glPopMatrix();
    }
  }
  //
  //Draw cars
    for (int i = 9; i > 5; i--) {
        matrix[3][0] = pos[0] + ((i % 3) * 6);
        matrix[3][2] = pos[1] + ((i / 3) * 6);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glMultMatrixf(matrix[0]);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, car_texture);
        glUseProgram(m_program);

        drawCar();

        glUseProgram(0);
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        glPopMatrix();

        if (i+1 == camera) {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(matrix[3][0],0.5,matrix[3][2],sin(roty)+matrix[3][0],sin(rotx)+0.2,-cos(roty)+matrix[3][2],0,1,0); //Camera rotation/translation is done here
        }
    }

  //Draw structures
  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++){

      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      //glTranslatef((i % 3) * 6, 0, (i / 3) * 6);
      glTranslatef((1.3-(i*2.0)), 0, (4+(j*2)));
      glEnable(GL_TEXTURE_2D);

      if((i % 2) != 0){
        glBindTexture(GL_TEXTURE_2D, structure_texture);
        glUseProgram(m_program);

        drawStructure();
      }else{
        glBindTexture(GL_TEXTURE_2D, house_texture);
        glUseProgram(m_program);

        drawHouse();
      }

      glUseProgram(0);
      glDisable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, 0);
      glPopMatrix();

    }
  }

  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++){

      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      //glTranslatef((i % 3) * 6, 0, (i / 3) * 6);
      glTranslatef((8-(i*2.0)), 0, (10.7+(j*2)));
      glEnable(GL_TEXTURE_2D);

      if((i % 2) != 0){
        glBindTexture(GL_TEXTURE_2D, structure_texture);
        glUseProgram(m_program);

        drawStructure();
      }else{
        glBindTexture(GL_TEXTURE_2D, house_texture);
        glUseProgram(m_program);

        drawHouse();
      }

      glUseProgram(0);
      glDisable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, 0);
      glPopMatrix();

    }
  }

  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++){

      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      //glTranslatef((i % 3) * 6, 0, (i / 3) * 6);
      glTranslatef(-(2.7-(i*2.0)), 0, -(-1.3+(j*2)));
      glEnable(GL_TEXTURE_2D);

      if((i % 2) != 0){
        glBindTexture(GL_TEXTURE_2D, structure_texture);
        glUseProgram(m_program);

        drawStructure();
      }else{
        glBindTexture(GL_TEXTURE_2D, house_texture);
        glUseProgram(m_program);

        drawHouse();
      }

      glUseProgram(0);
      glDisable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, 0);
      glPopMatrix();

    }
  }

  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++){

      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      //glTranslatef((i % 3) * 6, 0, (i / 3) * 6);
      glTranslatef(-(2.7-(i*2.0)), 0, -(-15+(j*2)));
      glEnable(GL_TEXTURE_2D);

      if((i % 2) != 0){
        glBindTexture(GL_TEXTURE_2D, structure_texture);
        glUseProgram(m_program);

        drawStructure();
      }else{
        glBindTexture(GL_TEXTURE_2D, house_texture);
        glUseProgram(m_program);

        drawHouse();
      }

      glUseProgram(0);
      glDisable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, 0);
      glPopMatrix();

    }
  }

  for (int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++){

      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      //glTranslatef((i % 3) * 6, 0, (i / 3) * 6);
      glTranslatef(-(-10.7-(i*2.0)), 0, -(-14.5+(j*2)));
      glEnable(GL_TEXTURE_2D);

      if((i % 2) != 0){
        glBindTexture(GL_TEXTURE_2D, structure_texture);
        glUseProgram(m_program);

        drawStructure();
      }else{
        glBindTexture(GL_TEXTURE_2D, house_texture);
        glUseProgram(m_program);

        drawHouse();
      }

      glUseProgram(0);
      glDisable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, 0);
      glPopMatrix();

    }
  }
  //

  //Draw skybox
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, skybox_texture);
  glUseProgram(m_program);

  drawSkybox();

  glUseProgram(0);
  glDisable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);
  //

  //Draw walls
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, wall_texture);
  glUseProgram(m_program);

  drawWalls();

  glUseProgram(0);
  glDisable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);
  //

  if (!camera) {
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      gluLookAt(cposx,up,cposz,sin(roty)+cposx,sin(rotx)+cposy,-cos(roty)+cposz,0,1,0);
  }

  glutSwapBuffers();

}

void City::mouseHandler(int button, int state, int x, int y){
  if (state == GLUT_UP)
      return;

  switch(button)  {
    case 0:
      x0 = x;
      y0 = y;
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
  }
}

void City::keyDown(unsigned char key, int, int){
  switch(key){

    case 'q':
      case 27:
        stop();
        break;
    case 'w':
      cposx += walk_speed * sin(roty);
      cposz -= walk_speed * cos(roty);

      break;
    case 'a':
      cposx -= walk_speed * cos(roty);
      cposz -= walk_speed * sin(roty);
      break;
    case 's':
      cposx -= walk_speed * sin(roty);
      cposz += walk_speed * cos(roty);
      break;
    case 'd':
      cposx += walk_speed * cos(roty);
      cposz += walk_speed * sin(roty);
      break;
  }
}

void City::specialKeyUp(int key, int, int){
  switch(key){
    case GLUT_KEY_UP:
      up += walk_speed * cos(roty);
    break;

    case GLUT_KEY_DOWN:
      if(up < 0.5)
        up = 0.25;
      up -= walk_speed * cos(roty);
    break;

    case GLUT_KEY_LEFT:
    break;

    case GLUT_KEY_RIGHT:
    break;
  }
}

void City::mouseMove(int x, int y){
  float dx = ((x - x0)) / 5.0;
  float dy = ((y - y0)) / 5.0;

  roty += dx * (PI / 180.0);
  rotx -= dy * (PI / 180.0);

  if(rotx > PI / 2)
    rotx = PI / 2;
  else if(rotx < (-1*(PI)) / 2)
    rotx = (-1*(PI)) / 2;

  x0 = x;
  y0 = y;
}

void City::stop(){
  glDetachShader(m_program,m_fragmentsh);
  glDeleteProgram(m_program);
  glDeleteShader(m_fragmentsh);
  exit(0);
}

void City::makeShaders(){
  m_program = glCreateProgram();

  char *shadercode = readShader("shaders/vertexshader.vert");
  m_vertexsh = glCreateShader(GL_VERTEX_SHADER_ARB);
  glShaderSource(m_vertexsh, 1, (const GLcharARB **)&shadercode,NULL);
  delete[] shadercode;
  glCompileShader(m_vertexsh);
  printInfoLog(m_vertexsh);

  shadercode = readShader("shaders/fragmentshader.frag");
  m_fragmentsh = glCreateShader(GL_FRAGMENT_SHADER_ARB);
  glShaderSource(m_fragmentsh, 1, (const GLcharARB **)&shadercode,NULL);
  delete[] shadercode;
  glCompileShader(m_fragmentsh);
  printInfoLog(m_fragmentsh);

  glAttachShader(m_program,m_vertexsh);
  glAttachShader(m_program,m_fragmentsh);

  glLinkProgram(m_program);
  printInfoLog(m_program);
}

void City::run(){
  glutMainLoop();
}

void City::update(){
  m_frame++;
  glutPostRedisplay();
}

void City::drawCar(){
  glBegin(GL_QUADS);
  //Right lower
  glTexCoord2f(0,0.02);
  glNormal3f(0,0,1);
  glVertex3f(-.5,0,.19);
  glTexCoord2f(1,0.02);
  glNormal3f(0,0,1);
  glVertex3f(.5,0,.19);
  glTexCoord2f(1,0.21);
  glNormal3f(0,0,1);
  glVertex3f(.5,.21,.19);
  glTexCoord2f(0,0.21);
  glNormal3f(0,0,1);
  glVertex3f(-.5,.21,.19);
  //Right upper
  glTexCoord2f(0,0.21);
  glNormal3f(0,0,1);
  glVertex3f(-.5,.21,.19);
  glTexCoord2f(0.77,0.21);
  glNormal3f(0,0,1);
  glVertex3f(.27,.21,.19);
  glTexCoord2f(0.59,0.32);
  glNormal3f(0,0,1);
  glVertex3f(.09,.32,.16);
  glTexCoord2f(0.07,0.32);
  glNormal3f(0,0,1);
  glVertex3f(-.43,.32,.16);
  //Left lower
  glTexCoord2f(0,0.21);
  glNormal3f(0,0,-1);
  glVertex3f(-.5,.21,-.19);
  glTexCoord2f(1,0.21);
  glNormal3f(0,0,-1);
  glVertex3f(.5,.21,-.19);
  glTexCoord2f(1,0.02);
  glNormal3f(0,0,-1);
  glVertex3f(.5,0,-.19);
  glTexCoord2f(0,0.02);
  glNormal3f(0,0,-1);
  glVertex3f(-.5,0,-.19);
  //Left upper
  glTexCoord2f(0.07,0.32);
  glNormal3f(0,0,-1);
  glVertex3f(-.43,.32,-.16);
  glTexCoord2f(0.59,0.32);
  glNormal3f(0,0,-1);
  glVertex3f(.09,.32,-.16);
  glTexCoord2f(0.77,0.21);
  glNormal3f(0,0,-1);
  glVertex3f(.27,.21,-.19);
  glTexCoord2f(0,0.21);
  glNormal3f(0,0,-1);
  glVertex3f(-.5,.21,-.19);
  //Front grill
  glTexCoord2f(0.57,0.79);
  glNormal3f(1,0,0);
  glVertex3f(.5,0,.19);
  glTexCoord2f(0.94,0.79);
  glNormal3f(1,0,0);
  glVertex3f(.5,0,-.19);
  glTexCoord2f(0.94,0.97);
  glNormal3f(1,0,0);
  glVertex3f(.5,.21,-.19);
  glTexCoord2f(0.57,0.97);
  glNormal3f(1,0,0);
  glVertex3f(.5,.21,.19);
  //Hood
  glTexCoord2f(0.92,0.42);
  glNormal3f(0,1,0);
  glVertex3f(.5,.21,.19);
  glTexCoord2f(0.92,0.69);
  glNormal3f(0,1,0);
  glVertex3f(.5,.21,-.19);
  glTexCoord2f(0.71,0.69);
  glNormal3f(0,1,0);
  glVertex3f(.27,.21,-.19);
  glTexCoord2f(0.71,0.42);
  glNormal3f(0,1,0);
  glVertex3f(.27,.21,.19);
  //Windshield
  glTexCoord2f(0.70,0.42);
  glNormal3f(0,1,0);
  glVertex3f(.27,.21,.19);
  glTexCoord2f(0.70,0.69);
  glNormal3f(0,1,0);
  glVertex3f(.27,.21,-.19);
  glTexCoord2f(0.54,0.69);
  glNormal3f(0,1,0);
  glVertex3f(.09,.32,-.16);
  glTexCoord2f(0.54,0.42);
  glNormal3f(0,1,0);
  glVertex3f(.09,.32,.16);
  //Roof
  glTexCoord2f(0.50,0.46);
  glNormal3f(0,1,0);
  glVertex3f(.09,.32,.16);
  glTexCoord2f(0.50,0.67);
  glNormal3f(0,1,0);
  glVertex3f(.09,.32,-.16);
  glTexCoord2f(0.07,0.67);
  glNormal3f(0,1,0);
  glVertex3f(-.43,.32,-.16);
  glTexCoord2f(0.07,0.46);
  glNormal3f(0,1,0);
  glVertex3f(-.43,.32,.16);
  //Back lower
  glTexCoord2f(0.08,0.73);
  glNormal3f(-1,0,0);
  glVertex3f(-.5,0,-.19);
  glTexCoord2f(0.44,0.73);
  glNormal3f(-1,0,0);
  glVertex3f(-.5,0,.19);
  glTexCoord2f(0.44,0.88);
  glNormal3f(-1,0,0);
  glVertex3f(-.5,.21,.19);
  glTexCoord2f(0.08,0.88);
  glNormal3f(-1,0,0);
  glVertex3f(-.5,.21,-.19);
  //Back upper
  glTexCoord2f(0.08,0.88);
  glNormal3f(-1,0,0);
  glVertex3f(-.5,.21,-.19);
  glTexCoord2f(0.44,0.88);
  glNormal3f(-1,0,0);
  glVertex3f(-.5,.21,.19);
  glTexCoord2f(0.42,1);
  glNormal3f(-1,0,0);
  glVertex3f(-.43,.32,.16);
  glTexCoord2f(0.12,1);
  glNormal3f(-1,0,0);
  glVertex3f(-.43,.32,-.16);

  glEnd();
}

void City::drawStructure(){
  glBegin(GL_QUADS);
  glTexCoord2f(0,0);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,0.01,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,5,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,5,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,5,-6.5);
  //Front
  glTexCoord2f(0,0);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,0,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,0,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,5,-5.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,5,-5.5);
  //Right
  glTexCoord2f(0,0);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0,-6.5);
  glTexCoord2f(1,1);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,5,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,5,-5.5);
  //Back
  glTexCoord2f(0,0);
  glNormal3f(0,0,-1);
  glVertex3f(-5.5,0,-6.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,-1);
  glVertex3f(-6.5,0,-6.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,-1);
  glVertex3f(-6.5,5,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,-1);
  glVertex3f(-5.5,5,-6.5);
  //Left
  glTexCoord2f(0,0);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0,-6.5);
  glTexCoord2f(1,0);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,5,-5.5);
  glTexCoord2f(0,1);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,5,-6.5);

  glEnd();
}

void City::drawGrass(){
  glBegin(GL_QUADS);

  glTexCoord2f(0,0);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,0.01,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,0.01,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,0.01,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,0.01,-6.5);


  //Front
  glTexCoord2f(0,0);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,0,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,0,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,0.01,-5.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,0.01,-5.5);
  //Right
  glTexCoord2f(0,0);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0,-6.5);
  glTexCoord2f(1,1);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0.01,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0.01,-5.5);
  //Back
  glTexCoord2f(0,0);
  glNormal3f(0,0,-1);
  glVertex3f(-5.5,0,-6.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,-1);
  glVertex3f(-6.5,0,-6.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,-1);
  glVertex3f(-6.5,0.01,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,-1);
  glVertex3f(-5.5,0.01,-6.5);
  //Left
  glTexCoord2f(0,0);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0,-6.5);
  glTexCoord2f(1,0);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0.01,-5.5);
  glTexCoord2f(0,1);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0.01,-6.5);

  glEnd();
}

void City::drawHouse(){
  glBegin(GL_QUADS);
  glTexCoord2f(0,0);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,2,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,2,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,2,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,2,-6.5);

  //Front
  glTexCoord2f(0,0);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,0,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,0,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,1);
  glVertex3f(-5.5,2,-5.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,1);
  glVertex3f(-6.5,2,-5.5);
  //Right
  glTexCoord2f(0,0);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0,-5.5);
  glTexCoord2f(1,0);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,0,-6.5);
  glTexCoord2f(1,1);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,2,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(1,0,0);
  glVertex3f(-5.5,2,-5.5);
  //Back
  glTexCoord2f(0,0);
  glNormal3f(0,0,-1);
  glVertex3f(-5.5,0,-6.5);
  glTexCoord2f(1,0);
  glNormal3f(0,0,-1);
  glVertex3f(-6.5,0,-6.5);
  glTexCoord2f(1,1);
  glNormal3f(0,0,-1);
  glVertex3f(-6.5,2,-6.5);
  glTexCoord2f(0,1);
  glNormal3f(0,0,-1);
  glVertex3f(-5.5,2,-6.5);
  //Left
  glTexCoord2f(0,0);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0,-6.5);
  glTexCoord2f(1,0);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,0,-5.5);
  glTexCoord2f(1,1);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,2,-5.5);
  glTexCoord2f(0,1);
  glNormal3f(-1,0,0);
  glVertex3f(-6.5,2,-6.5);

  glEnd();
}

void City::drawSkybox(){
  glBegin(GL_QUADS);
  //Back
  glTexCoord2f(.5,1.0/3.0);
  glVertex3f(500,-500,-500);
  glTexCoord2f(.5,2.0/3.0);
  glVertex3f(500,500,-500);
  glTexCoord2f(.25,2.0/3.0);
  glVertex3f(-500,500,-500);
  glTexCoord2f(.25,1.0/3.0);
  glVertex3f(-500,-500,-500);
  //Front
  glTexCoord2f(1,0.334);
  glVertex3f(-500,-500,500);
  glTexCoord2f(1,0.665);
  glVertex3f(-500,500,500);
  glTexCoord2f(.75,0.665);
  glVertex3f(500,500,500);
  glTexCoord2f(.75,0.334);
  glVertex3f(500,-500,500);
  //Left
  glTexCoord2f(0,0.334);
  glVertex3f(-500,-500,500);
  glTexCoord2f(.25,0.334);
  glVertex3f(-500,-500,-500);
  glTexCoord2f(.25,0.665);
  glVertex3f(-500,500,-500);
  glTexCoord2f(0,0.665);
  glVertex3f(-500,500,500);
  //Right
  glTexCoord2f(.5,0.334);
  glVertex3f(500,-500,-500);
  glTexCoord2f(.75,0.334);
  glVertex3f(500,-500,500);
  glTexCoord2f(.75,0.665);
  glVertex3f(500,500,500);
  glTexCoord2f(.5,0.665);
  glVertex3f(500,500,-500);
  //Top
  glTexCoord2f(.251,2.0/3.0);
  glVertex3f(-500,500,-500);
  glTexCoord2f(.499,2.0/3.0);
  glVertex3f(500,500,-500);
  glTexCoord2f(.499,1.0);
  glVertex3f(500,500,500);
  glTexCoord2f(.251,1.0);
  glVertex3f(-500,500,500);
  //Bottom
  glTexCoord2f(.251,1.0/3.0);
  glVertex3f(-500,-500,-500);
  glTexCoord2f(.251,0.0/3.0);
  glVertex3f(-500,-500,500);
  glTexCoord2f(.499,0.0/3.0);
  glVertex3f(500,-500,500);
  glTexCoord2f(.499,1.0/3.0);
  glVertex3f(500,-500,-500);


  glEnd();
}

void City::drawWalls(){
  glBegin(GL_QUADS);

  glTexCoord2f(0,0);
  glVertex3f(-10,0,-10);
  glTexCoord2f(0,20);
  glVertex3f(10,0,-10);
  glTexCoord2f(1,20);
  glVertex3f(10,0.5,-10);
  glTexCoord2f(1,0);
  glVertex3f(-10,0.5,-10);

  glTexCoord2f(0,0);
  glVertex3f(10,0,-10);
  glTexCoord2f(0,20);
  glVertex3f(10,0,10);
  glTexCoord2f(1,20);
  glVertex3f(10,0.5,10);
  glTexCoord2f(1,0);
  glVertex3f(10,0.5,-10);

  glTexCoord2f(0,0);
  glVertex3f(10,0,10);
  glTexCoord2f(0,20);
  glVertex3f(-10,0,10);
  glTexCoord2f(1,20);
  glVertex3f(-10,0.5,10);
  glTexCoord2f(1,0);
  glVertex3f(10,0.5,10);

  glTexCoord2f(0,0);
  glVertex3f(-10,0,10);
  glTexCoord2f(0,20);
  glVertex3f(-10,0,-10);
  glTexCoord2f(1,20);
  glVertex3f(-10,0.5,-10);
  glTexCoord2f(1,0);
  glVertex3f(-10,0.5,10);

  glEnd();
}
