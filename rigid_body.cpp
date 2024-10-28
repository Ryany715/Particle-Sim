#include <iostream>
#include <vector>
using namespace std;

class RigidBody
{
    private:
        vector<double> accel(vector<double> forces, int mass){
        // this gets the current accelration of the body based on the force acting on it at the current tick. It uses its own mass.
        vector<double> dvdt = forces; 
        for (int i = 0; i < forces.size(); i ++){ 
            dvdt[i] = forces[i] / mass;
        }
        return dvdt;
        };

    vector<double> vel(vector<double> forces, int mass, float dt, vector<double>& dxdt) {
        // this function calculates the body's current velocity.
        vector<double> dvdt = accel(forces, mass);
        for (int i = 0; i < dvdt.size(); i ++) {
            dxdt[i] = dxdt[i] + (dvdt[i] * dt);
        };
        return dxdt;
        };
    public:
        vector<double> position;
        vector<double> velocity;
        vector<double> acceleration;
        vector<double> force;
        int bodymass;


        vector<double> applyForce(vector<double> actingforce, float dt) {
            // we need a function here that takes ina a force vector and applies it to the body through initilaiztion. Really we need to set the applied force to be some vector at a given step
            // which means this method could be called a bunch of times to apply/unapply a force at a tick a bunch of times. Rigid bodies can apply foirces to other bodies and can have force 
            // applied to them. This should simply set the force vector for the current body
            force = actingforce;
            vector<double> newvel = vel(force, bodymass, dt, velocity);
            velocity = newvel;
            return newvel;
        };

        RigidBody(vector<double> initialpos, vector<double> initialforce, int mass, vector<double>& initialvel, float dt){
            // the rigid body is intialized with an external force if there is one. From there the code needs to continually recalculate the position and velocity based on how forces change with each tick
            // of time. How to determine that time is a bit of a question right now. After the initalzation of the rigid body we want to know its output momentum. This will allow us to divine the direction
            // it is moving and how fast. The dirivative of the momentum vector w.r.t will be the force vetor as well. So from one step to the next if momentum in increasing, then we know a force is being
            // applied to the body. Will need a way to calculate the direvative w.r.t time/tick. 
            bodymass = mass;
            position = initialpos;
            force = initialforce;
            // now get the accelration and velocity based on initial conditions acting on the body. These are essentially beiong set for the next time step? 
            // not sure if we set them here or need a counter for setting next
            velocity = vel(force, bodymass, dt, initialvel);
            };
};