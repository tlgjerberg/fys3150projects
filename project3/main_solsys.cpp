#include "planet.h"
#include "solar_system.h"
#include "solver.h"
// #include "vec3.h"

int main(int argc, char const *argv[]) {
  double t = 12.0;
  int n = 10000;
  int N = n * t;
  double h = t / N;
  double days = 365;
  SolarSystem solsys;
  vec pos1 = {8.762968100249854E-01, 4.788339338174544E-01,
              -9.307050339169484E-05};
  vec vel1 = {-8.439075390315470E-03 * 365, 1.508194738302731E-02 * 365,
              -1.191747734059677E-07 * 365};
  vec pos2 = {-2.082456923795519E-04, 7.269365845327120E-03,
              -7.116216262733176E-05};
  vec vel2 = {-7.605663822232906E-06 * 365, 2.520655405552306E-06 * 365,
              1.901417766099408E-07 * 365};
  vec pos3 = {-2.608627805978873E+00, -4.685828309297189E+00,
              7.778573346168467E-02};
  vec vel3 = {6.502462708302700E-03 * 365, -3.310060301323844E-03 * 365,
              -1.317114883681856E-04 * 365};
  planet planet1(pos1, vel1, 0.000003);
  planet planet2(pos2, vel2, 1);
  planet planet3(pos3, vel3, 0.00095);

  // cout << planet1.position << endl;
  // cout << planet2.position << endl;
  solsys.add_celestial_objects(planet1);
  solsys.add_celestial_objects(planet2);

  // vector <planet> cel_obj;
  // cel_obj = solsys.objects();
  // cout << "cel_obj[1] position" << cel_obj[1].position << endl;

  solsys.add_celestial_objects(planet3);
  // cout << solsys.length() << endl;
  // cout << planet1.distance(planet2) << endl;
  // cout << solsys.accel() << endl;
  // cout << solsys.position() << endl;

  // vec gforce = planet1.GForce(planet2);
  solver binobj;
  binobj.verlet(solsys, N, h);
  // binobj.euler(planet1, planet2, N, h);
  return 0;
}
