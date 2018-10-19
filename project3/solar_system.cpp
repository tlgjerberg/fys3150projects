#include "planet.h"
#include "solar_system.h"
#include "solver.h"

SolarSystem::SolarSystem() { vector<planet> celestial_objects = {}; }
SolarSystem::SolarSystem(vector<planet> init_cel_obj) {
  celestial_objects = init_cel_obj;
}

void SolarSystem::add_celestial_objects(planet planet) {
  celestial_objects.push_back(planet);
}
int SolarSystem::length() { return celestial_objects.size(); }

mat SolarSystem::position() {
  int n = celestial_objects.size();
  mat pos = zeros(3, n);
  for (int i = 0; i < n; i++) {
    pos(0, i) = celestial_objects[i].x;
    pos(1, i) = celestial_objects[i].y;
    pos(2, i) = celestial_objects[i].z;
  }
  return pos;
}

mat SolarSystem::velocity() {
  int n = celestial_objects.size();
  mat vel = zeros(3, n);
  for (int i = 0; i < n; i++) {
    vel(0, i) = celestial_objects[i].vx;
    vel(1, i) = celestial_objects[i].vy;
    vel(2, i) = celestial_objects[i].vz;
  }
  return vel;
}

mat SolarSystem::accel() {
  int n = celestial_objects.size();
  mat A = zeros(3, n);
  for (int i = 0; i < n; i++) {
    vec accel = celestial_objects[i].accel(celestial_objects[i + 1]);

    for (int j = i + 1; j < n; j++) {
      A(0, j) += accel(0);
      A(1, j) += accel(1);
      A(2, j) += accel(2);
    }
  }
  return A;
}
