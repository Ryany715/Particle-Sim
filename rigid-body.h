#include <iostream>
#include <vector>
#include "io.h"

using namespace std;

// this will be delta t, for know define it as a set global variable
const int dt = .001;


class RigidBody{
private:
    vector<double> getCurrAccel(vector<double> forces){
        // this gets the current accelration of the body based on the force acting on it at the current tick. It uses its own mass.
        for (int i = 0; i < forces.size(); i ++){ 
            accel[i] = forces[i] / bodymass;
        }
    };
    vector<double> getVelocity(vector<double> initalVelocity, vector<double> accel, int deltat) {
        // this function calculates the body's current velocity.
        vector<double> finalVelocity;
        for (int i =0; i< initalVelocity.size(); i ++) {
            finalVelocity[i] = initalVelocity[i] + (accel[i] * deltat);
        };
        return finalVelocity;
    };

public:
    vector<double> pos;
    vector<double> accel;
    vector<double> vel;
    int bodymass;

    void applyForce(vector<double> actingforce) {
        // we need a function here that takes ina a force vector and applies it to the body through initilaiztion. Really we need to set the applied force to be some vector at a given step
        // which means this method could be called a bunch of times to apply/unapply a force at a tick a bunch of times. Rigid bodies can apply foirces to other bodies and can have force 
        // applied to them. This should simply set the force vector for the current body
        vector<double> force = actingforce;
    };


RigidBody(vector<double> initialpos, vector<double> initialforce, int mass, vector<double> initialvel){
    // the rigid body is intialized with an external force if there is one. From there the code needs to continually recalculate the position and velocity based on how forces change with each tick
    // of time. How to determine that time is a bit of a question right now. After the initalzation of the rigid body we want to know its output momentum. This will allow us to divine the direction
    // it is moving and how fast. The dirivative of the momentum vector w.r.t will be the force vetor as well. So from one step to the next if momentum in increasing, then we know a force is being
    // applied to the body. Will need a way to calculate the direvative w.r.t time/tick. 
    bodymass = mass;
    pos = initialpos;
    // now get the accelration and velocity based on initial conditions acting on the body. These are essentially beiong set for the next time step? 
    // not sure if we set them here or need a counter for setting next
    accel = getCurrAccel(initialforce);
    vel = getVelocity(initialvel, accel, dt);
    }   
};