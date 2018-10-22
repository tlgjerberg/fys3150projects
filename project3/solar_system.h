#ifndef Solar_system_H
#define Solar_system_H

#define _USE_MATH_DEFINES

#include "planet.h"
// #include "solver.h"
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace arma;

class SolarSystem {
private:
  double G = 4 * M_PI * M_PI;

public:
  vector<planet> celestial_objects;

  // Methods
  SolarSystem();
  SolarSystem(vector<planet> init_cel_obj);
  ~SolarSystem(){};
  int length();
  void add_celestial_objects(planet planet);
  mat Forces();
  mat accel();
  vector<planet> objects();
  // mat position();
  // mat velocity();
};

#endif // Solar_system_H
