/* Lorenz Equations
 * dx/dt = sig*(y - x)
 * dy/dt = x*(rho - z) - y
 * dz/dt = x*y - beta*z
 * parameters:
 * sig = 10.0
 * beta = 8/3
 * rho = 28.0
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#define D 0.002
#define C 0.001
#define K1 10.0
#define K2 2.0

using namespace std;

double fp (double t, vector<double>& r);
double fq (double t, vector<double>& r);
vector<double> rungeKutta (double dt, double t, vector<double>& r);

int main () {
    ofstream output;
    vector<double> r, rx;
    double dt, t, T;
    T = 5;
    t = 0;
    dt = 0.005;
    r.clear();
    rx = {100, 10000};
    output.open("MidTerm5_20915301_PrasetiyoHadiPurwoko.out");
    while (t < T) {
        output << setprecision(3) << fixed;
        for (int i=0; i<rx.size(); i++) output << rx[i] << "\t";
        output << endl;
        r = rungeKutta(dt, t, rx);
        t += dt;
        rx = r;
    }
    output.close();
    return 0;
}

double fp (double t, vector<double>& r) {
    return K1*r[0] - C*r[0]*r[1];
}

double fq (double t, vector<double>& r) {
    return -1*K2*r[1] + D*r[0]*r[1];
}

vector<double> rungeKutta (double dt, double t, vector<double>& r) {
    vector<double> rt, rx;
    double k1, k2, k3, k4;
    for (int i=0; i<r.size(); i++) rx.push_back(0);
    rt = r; k1 = fp(t, rt);
    rt[0] = r[0]+k1*dt/2; k2 = fp(t+dt/2, rt);
    rt[0] = r[0]+k2*dt/2; k3 = fp(t+dt/2, rt);
    rt[0] = r[0]+k3*dt; k4 = fp(t+dt, rt);
    rx[0] = r[0] + (k1+2*k2+2*k3+k4)*dt/6;
    rt = r; k1 = fq(t, rt);
    rt[1] = r[1]+k1*dt/2; k2 = fq(t+dt/2, rt);
    rt[1] = r[1]+k2*dt/2; k3 = fq(t+dt/2, rt);
    rt[1] = r[1]+k3*dt; k4 = fq(t+dt, rt);
    rx[1] = r[1] + (k1+2*k2+2*k3+k4)*dt/6;
    return rx;
}
