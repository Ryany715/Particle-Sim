#include <iostream>
#include <vector>
#include "rigid_body.cpp" // defines the physics for a rigid body and the class itself
#include "include/user_input.h" // defines the inital conditions for the code
#include "include/io.h" // defines functions for printing to the console
#include "include/timer.h"
#include "include/rk_r4.h"

using namespace std;

int main() {
  // start the simulation timer
  Timer simTimer;
  RigidBody TestBody(0, startpos, FGRAV, mass, startvel, dt_input);
  // this creates a pointer to the accel function in Rigid body
  void (RigidBody::*func)(double, vector<double>, vector<double>&) = &RigidBody::accel;
  // now calling the rk4 function using the pointer that was just created
  rk4_fixed(totalTime, TestBody.velocity, (TestBody.*func)(TestBody.bodymass, TestBody.force, TestBody.dvdt), dt_input);
  // in the context of the rk4 methodology x in position, dxdt is velocity and dvdt(d''xdt) is accelration, which is deterministic
  vecPrint("Initial TestBody dvdt", TestBody.velocity);
  // this is endless loop condition - solve for velocity without knowing how many steps
  simTimer.elapsedTime();
  vecPrint("Curr TestBody dvdt", TestBody.velocity);
  // debug params
  return TestBody.bodymass;
} 