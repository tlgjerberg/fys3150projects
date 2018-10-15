#ifndef Solar_system_H
#define Solar_system_H

#include "planet.h"
#include "vec3.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class SolarSystem {
public:
  vector<planet *> celestial_objects;

  // Methods
  SolarSystem();
  ~SolarSystem();
  void add_celestial_objects(planet *planet) {
    celestial_objects.push_back(planet);
  }
};

#endif // Solar_system_H
