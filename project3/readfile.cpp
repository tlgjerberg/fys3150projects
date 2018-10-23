#include <armadillo>
#include <fstream>
#include <string>

using namespace arma;
using namespace std;

mat Readfile(string filename) {
  mat A = zeros(10, 3);
  ifstream infile(filename);
  vec x = zeros(10);
  vec y = zeros(10);
  vec z = zeros(10);
  if (infile.is_open()) {
    for (int i = 0; i < 10; i++) {
      infile >> x(i) >> y(i) >> z(i);
      // cout << line << '\n';
      A(i, 0) = x(i);
      A(i, 1) = y(i);
      A(i, 2) = z(i);
    }
    infile.close();
  }

  else
    cout << "Unable to open file" << endl;

  return A;
}

int main(int argc, char const *argv[]) {
  mat pos = Readfile("pos_values.txt");
  cout << pos << endl;
  mat vel = Readfile("vel_values.txt");
  cout << vel << endl;
  return 0;
}
