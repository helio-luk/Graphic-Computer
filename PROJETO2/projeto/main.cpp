#include <iostream>
#include "City.hpp"

int main(int argc, char** argv){

  City city = City::init(argc,argv);
  city.run();

  return 0;
}
