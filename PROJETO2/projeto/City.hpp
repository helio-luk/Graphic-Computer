#ifndef _CITY_HPP_
#define _CITY_HPP_

class City{
private:
  static unsigned int m_program;
  static unsigned int m_vertexsh;
  static unsigned int m_fragmentsh;
  static int m_pos_attribute_location;
  static unsigned int m_vertexbuffer;
  static unsigned int m_frame;
  static const unsigned int m_width = 800;
  static const unsigned int m_height = 800;
  static int camera;
  static int x0, y0;
  static float rotx, roty, rotz;
  static float up;
  static float cposx, cposy, cposz;
  static float zoom;
  static float walk_speed;
  static void render();
  static void update();
  static void mouseHandler(int button, int state, int x, int y);
  static void keyDown(unsigned char key, int, int);

  static void specialKeyUp(int key, int, int);
  static void mouseMove(int x, int y);
  static void stop();
  static void initOpenGL();
  static void drawCubes();
  static void makeShaders();
  static void drawCar();
  static void drawStructure();
  static void drawHouse();
  static void drawGrass();
  static void drawSkybox();
  static void drawWalls();
  City(int argc, char **argv);
  static void checkExtensions();

public:
  static City &init(int argc, char** argv)
  {
      static City gw(argc, argv);
      return gw;
  }
  static void run();
};
#endif
