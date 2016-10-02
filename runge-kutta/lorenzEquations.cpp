/* Lorenz Equations
 * dx/dt = sig*(y - x)
 * dy/dt = x*(rho - z) - y
 * dz/dt = x*y - beta*z
 * parameters:
 * sig = 10.0
 * beta = 8/3
 * rho = 28.0
 */

#include <iomanip>
#include <iostream>
#include <vector>
#define SIG 10.0
#define BETA 8.0/3.0
#define RHO 28.0

using namespace std;

double fx (double t, vector<double>& r);
double fy (double t, vector<double>& r);
double fz (double t, vector<double>& r);
vector<double> rungeKutta (double dt, double t, vector<double>& r);

int main () {
    vector<double> r, rx;
    double dt, N, t, T;
    T = 30;
    t = 0;
    N = 50000;
    dt = (T - t)/N;
    r.clear();
    rx = {-10.0, -10.0, -5.0};
    while (t < T) {
        cout << setprecision(3) << fixed;
        for (int i=0; i<rx.size(); i++) cout << rx[i] << "\t";
        cout << endl;
        r = rungeKutta(dt, t, rx);
        t += dt;
        rx = r;
    }
    return 0;
}

double fx (double t, vector<double>& r) {
    return SIG*(r[1] - r[0]);
}

double fy (double t, vector<double>& r) {
    return r[0]*(RHO - r[2]) - r[1];
}

double fz (double t, vector<double>& r) {
    return r[0]*r[1] - BETA*r[2];
}

vector<double> rungeKutta (double dt, double t, vector<double>& r) {
    vector<double> rt, rx;
    double k1, k2, k3, k4;
    for (int i=0; i<r.size(); i++) rx.push_back(0);
    rt = r; k1 = fx(t, rt);
    rt[0] = r[0]+k1*dt/2; k2 = fx(t+dt/2, rt);
    rt[0] = r[0]+k2*dt/2; k3 = fx(t+dt/2, rt);
    rt[0] = r[0]+k3*dt; k4 = fx(t+dt, rt);
    rx[0] = r[0] + (k1+2*k2+2*k3+k4)*dt/6;
    rt = r; k1 = fy(t, rt);
    rt[1] = r[1]+k1*dt/2; k2 = fy(t+dt/2, rt);
    rt[1] = r[1]+k2*dt/2; k3 = fy(t+dt/2, rt);
    rt[1] = r[1]+k3*dt; k4 = fy(t+dt, rt);
    rx[1] = r[1] + (k1+2*k2+2*k3+k4)*dt/6;
    rt = r; k1 = fz(t, rt);
    rt[2] = r[2]+k1*dt/2; k2 = fz(t+dt/2, rt);
    rt[2] = r[2]+k2*dt/2; k3 = fz(t+dt/2, rt);
    rt[2] = r[2]+k3*dt; k4 = fz(t+dt, rt);
    rx[2] = r[2] + (k1+2*k2+2*k3+k4)*dt/6;
    return rx;
}
