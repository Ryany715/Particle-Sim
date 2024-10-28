#include <iostream>
#include <vector>
using namespace std;

class RigidBody
{
    private:

    public:
        vector<double> position;
        vector<double> velocity;
        vector<double> dvdt;
        vector<double> force;
        double bodymass;

        vector<double> applyForce(vector<double> actingforce, double dt) {
            // we need a function here that takes ina a force vector and applies it to the body through initilaiztion. Really we need to set the applied force to be some vector at a given step
            // which means this method could be called a bunch of times to apply/unapply a force at a tick a bunch of times. Rigid bodies can apply foirces to other bodies and can have force 
            // applied to them. This should simply set the force vector for the current body
            force = actingforce;
            return force;
        };

        void accel(double mass, vector<double> forces, vector<double>& dvdt){
        // this gets the current accelration of the body based on the force acting on it at the current tick. It uses its own mass.
        for (int i = 0; i < dvdt.size(); i ++){ 
            dvdt[i] = forces[i] / mass;
            }
        return; 
        };

        RigidBody(double startTime, vector<double> initialpos, vector<double> initialforce, double mass, vector<double>& initialvel, double dt){
            // the rigid body is intialized with an external force if there is one. From there the code needs to continually recalculate the position and velocity based on how forces change with each tick
            // of time. How to determine that time is a bit of a question right now. After the initalzation of the rigid body we want to know its output momentum. This will allow us to divine the direction
            // it is moving and how fast. The dirivative of the momentum vector w.r.t will be the force vetor as well. So from one step to the next if momentum in increasing, then we know a force is being
            // applied to the body. Will need a way to calculate the direvative w.r.t time/tick. 
            bodymass = mass;
            position = initialpos;
            force = initialforce;
            velocity = initialvel;
            for (int i = 0; i < velocity.size(); i ++){ 
                dvdt[i] = 0;
            }
            };
};