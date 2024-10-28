#include <iostream>
#include <vector>
#include "rigid_body.cpp" // defines the physics for a rigid body and the class itself
#include "include/user_input.h" // defines the inital conditions for the code
#include "include/io.h" // defines functions for printing to the console
#include "include/rk_r4.h"

using namespace std;

int main() {
    // test case to create a rigidbbody with gravity acting on it only
    // for now we hard code in initial conditions, but these need to be dynamic in the future
    RigidBody TestBody(startpos, FGRAV, mass, startvel, dt_input);
    vecPrint("Initial TestBody dvdt", TestBody.velocity);
    float curr_time = 0.0;
    // this is endless loop condition - solve for velocity without knowing how many steps
    while (curr_time < totalTime){
      TestBody.applyForce(FGRAV, dt_input);
      curr_time += dt_input;
      vecPrint("Curr TestBody dvdt", TestBody.velocity);
      floatPrint("Curr Sim Time", curr_time);
    }
  // debug params
  return TestBody.bodymass;
} 