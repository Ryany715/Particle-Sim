// implmentation of 4th order rungakutta model 
// this is valid for first order ODEs for a fixed step length

/*
    x: independent variable, what the deriviative is wrt
    y: dependent variables
    h: the fixed step length, in many cases this will be time

    Requires right-hand side routine
    void rhs_eval (double x, vector<double> y, vector<double>& dydx)
    which evaluates derivatives of y (w.r.t. x) in vector dydx

*/
#include <math.h>
#include <vector>

void rk4_fixed(double& x, vector<double>& y, void (*rhs_eval)(double, vector<double>, vector<double>&), double h){
    int n = y.size(); // this is the size of the vector y, or number of dependents

    vector<double> k1(n), k2(n), k3(n), k4(n), f(n), dydx(n); // declaring the vectors used for rk4
    
    // first RK step
    (*rhs_eval) (x, y, dydx); 
    for (int j = 0; j < n; j++){
        k1[j] = h * dydx[j];
        f[j] = y[j] + k1[j] / 2.0;
    }
    // Second RK step 
    (*rhs_eval) (x + h / 2.0, f, dydx);
    for (int j = 0; j < n; j++){
        k2[j] = h * dydx[j];
        f[j] = y[j] + k2[j] / 2.0;
    }
    //Third RK step
    (*rhs_eval) (x + h / 2.0, f, dydx);
    for (int j = 0; j < n; j++){
        k3[j] = h * dydx[j];
        f[j] = y[j] + k3[j] / 2.0;
    }

    //Combine the RK steps 
    for (int j = 0; j < n; j++){
        y[j] += k1[j] / 6.0 + k2[j] / 3.0 + k3[j] / 3.0 + k4[j] / 6.0;
    }
    x += h;
    return;
}