// Prasetiyo Hadi Purwoko
// 20915301
#include <iostream>
#include <cmath>
// define gravity acceleration (m/s^2)
#define GA   -9.8

int main () {
    double h, t, v, va, vt;
    double a, ar, Ar, dt, f, F, m, k;

    // initial state
    // initial time
    t = 0;
    // initial velocity (m/s)
    v = 0;
    vt = 0;
    // initial height (m)
    h = 2000;
    // timestep (s)
    dt = 0.01;
    // mass (kg)
    m = 90;
    // cross-section area (m^2) when parachute is closed
    ar = 0.4;
    // cross-section area (m^2) when parchute is open
    Ar = 28;
    // air friction coefficient (kg/m^3)
    k = -0.65;

    while (h > 0) {
        in = false;
        std::cout << t << "\t" << h << "\t" << v << std::endl;
        if (h > 1000)
            f = k*ar*v*std::fabs(v);
        else if (h <= 1000)
            f = k*Ar*v*std::fabs(v);
        F = m*GA+f;
        a = F/m;
        va = vt + a*dt;
        if (h > 1000)
            f = k*ar*va*std::fabs(va);
        else if (h <= 1000)
            f = k*Ar*va*std::fabs(va);
        F = m*GA+f;
        a = F/m;
        v = vt + a*dt;
        h += v*dt;
        t += dt;
        vt = v;
    }
    return 0;
}
