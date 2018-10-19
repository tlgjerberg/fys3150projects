#ifndef Solar_system_H
#define Solar_system_H

#include "planet.h"
// #include "solver.h"
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
// using namespace arma;

class SolarSystem {
public:
  vector<planet> celestial_objects;

  // Methods
  SolarSystem();
  SolarSystem(vector<planet> init_cel_obj);
  ~SolarSystem(){};
  int length();
  void add_celestial_objects(planet planet);
  mat accel();
  mat position();
};

#endif // Solar_system_H
