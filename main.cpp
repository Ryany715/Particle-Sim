#include <iostream>
#include "rigid-body.h"
#include "io.h"
using namespace std;

const vector<double> fgrav{0, -9.81, 0};

int main() {
  // test case to create a rigidbbody with gravity acting on it only
  // for now we hard code in initial conditions, but these need to be dynamic in the future
  vector<double> startpos{0 , 100, 0};
  vector<double> startvel{0 , 30, 0};
  int mass = 10;
  RigidBody TestBody(startpos, fgrav, mass, startvel);
  intPrint("mass", TestBody.bodymass);
  vecPrint("TestBody velocity", TestBody.vel);
  vecPrint("TestBody accel", TestBody.accel);
} 