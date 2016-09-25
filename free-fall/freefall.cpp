#include <iostream>
#include <cmath>
// define gravity acceleration (m/s^2)
#define GA   -9.8

int main () {
    double h, t, v, va, vt;
    double a, dt, f, F, m, r, k;

    // initial state
    // initial time
    t = 0;
    // initial velocity (m/s)
    v = 0;
    vt = 0;
    // initial height (m)
    h = 3000;
    // timestep (s)
    dt = 0.1;
    // mass (kg)
    m = 60;
    // object radius (m)
    r = 0.25;
    // air friction coefficient (kg/m^3)
    k = -0.65;

    while (h > 0) {
        std::cout << t << "\t" << h << "\t" << v << std::endl;
        f = k*M_PI*std::pow(r, 2)*v*std::fabs(v);
        F = m*GA;
        a = F/m;
        v = vt + a*dt;
        va = (v+vt)/2;
        h += va*dt;
        t += dt;
        vt = v;
    }
    return 0;
}
