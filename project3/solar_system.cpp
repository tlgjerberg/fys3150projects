#include "planet.h"
#include "solar_system.h"
// #include "solver.h"

SolarSystem::SolarSystem() { vector<planet> celestial_objects; }
SolarSystem::SolarSystem(vector<planet> init_cel_obj) {
  celestial_objects = init_cel_obj;
}

void SolarSystem::add_celestial_objects(planet planet) {
  celestial_objects.push_back(planet);
  cout << "earth position" << endl;
  cout << celestial_objects[0].position << endl;
}
int SolarSystem::length() {
  cout << "cel_obj size" << endl;
  cout << celestial_objects.size();
  return celestial_objects.size(); }

// mat SolarSystem::position() {
//   // int n = celestial_objects.size();
//   mat pos = zeros(3, n);
//   for (int i = 0; i < n; i++) {
//     pos(0, i) = celestial_objects[i].x;
//     pos(1, i) = celestial_objects[i].y;
//     pos(2, i) = celestial_objects[i].z;
//   }
//   return pos;
// }

// mat SolarSystem::velocity() {
//   int n = celestial_objects.size();
//   mat vel = zeros(3, n);
//   for (int i = 0; i < n; i++) {
//     vel(0, i) = celestial_objects[i].vx;
//     vel(1, i) = celestial_objects[i].vy;
//     vel(2, i) = celestial_objects[i].vz;
//   }
//   return vel;
// }

// mat SolarSystem::Forces() {
//   int n = celestial_objects.size();
//   mat F = zeros(3, n);
//   for (int i = 0; i < n; i++) {
//     planet object1 = &celestial_objects[i];
//     for (int j = i + 1; j < n; j++) {
//       planet object2 = &celestial_objects[j];
//
//       vec Force1 = object1.GForce(object2);
//       F(0, i) += Force1(0);
//       F(1, i) += Force1(1);
//       F(2, i) += Force1(2);
//     }
//   }
//   return F
// }

// mat SolarSystem::accel() {
//   int n = celestial_objects.size();
//   mat A = zeros(3, n);
//   for (int i = 0; i < n; i++) {
//
//     for (int j = i + 1; j < n; j++) {
//       // vec accel = celestial_objects[i].accel(celestial_objects[j]);
//       A(0, i) += -G*;
//       A(1, i) += accel(1);
//       A(2, i) += accel(2);
//     }
//   }
//   return A;
// }

mat SolarSystem::accel() {
  int n = celestial_objects.size();
  // cout << "n:" << n << endl;
  vec drvec;
  double r;
  mat A = zeros(3, n);
  for (int i = 0; i < n; i++) {

    for (int j = i + 1; j < n; j++) {
      cout << "cel_obj[i]"<< endl;
      cout << celestial_objects[i].position << endl;
      cout << "cel_obj[j]" << endl;
      cout << celestial_objects[j].position << endl;
      drvec = celestial_objects[j].position - celestial_objects[i].position;
      // cout << drvec << endl;
      r = celestial_objects[i].distance(celestial_objects[j]);
      // cout << r << endl;
      A.col(i) += -G*celestial_objects[j].mass*(drvec)/pow(r,3);
      // A(0, i) += -G * &celestial_objects[j].mass *
      //            (&celestial_objects[i].x - &celestial_objects[j].x) / pow(r, 2);
      // A(1, i) += -G * &celestial_objects[j].mass *
      //            (&celestial_objects[i].y - &celestial_objects[j].y) / pow(r, 2);
      // A(2, i) += -G * &celestial_objects[j].mass *
      //            (&celestial_objects[i].z - &celestial_objects[j].z) / pow(r, 2);
    }
  }
  return A;
}

vector<planet> SolarSystem::objects() { return celestial_objects; }
