#include <iostream>
#include <vector>
using namespace std;

// this file will set ther user variables used in the simulation. Eventually we want this to bne a GUI or siumilar interface
// for the neededed intial variables frrom the user. Ideally this won;t even need a time set at first
#define FGRAV  vector<double> {0, -9.81, 0}// global gravity force


// initally we are only simulating rigid body motion, test case one is a bal lthrown into the air and then coming back down to the ground
  
vector<double> startpos = {0 , 100, 0};
vector<double> startvel = {0 , 30, 0};
int mass = 10;


// time vars
const float totalTime = 0;
const float dt_input = .001;