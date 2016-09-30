/* Runge-Kutta 4 Method
 * initial value problem:
 * dy/dt = f(t, y) , y(t0) = y0
 * y_{n+1} = y_n + (k1 + 2*k2 + 2*k3 + k4)*h/6
 * t_{n+1} = t_n + h
 * y_{n+1} ~ y(t_{n+1})
 * k1 = f(t_n, y_n)
 * k2 = f(t_n + h/2, y_n + k1*h/2)
 * k3 = f(t_n + h/2, y_n + k2*h/2)
 * k4 = f(t_n + h, y_n + k3*h)
 */

#include <cmath>
#include <iostream>

double func (double t, double y);
double rungeKutta (double h, double t, double y);

int main () {
    bool loop;
    double err, h, t, T, y, yt;
    yt = 1;
    T = 1;
    t = 0;
    h = 0.1;
    err = std::pow(10, -4);
    loop = true;
    std::cout << "t\t\ty" << std::endl;
    while (t < T && loop) {
        std::cout << t << "\t\t" << yt << std::endl;
        y = rungeKutta(h, t, yt);
        t += h;
        if (std::fabs(y - yt) < err) loop = false;
        yt = y;
    }
    return 0;
}

double func (double t, double y) {
    /* define ordinary differential function here */
    return -2*y + t + 4;
}

double rungeKutta (double h, double t, double y) {
    double k1, k2, k3, k4;
    k1 = func(t, y);
    k2 = func(t+h/2, y+k1*h/2);
    k3 = func(t+h/2, y+k2*h/2);
    k4 = func(t+h, y+k3*h);
    return y + (k1 + 2*k2 + 2*k3 + k4)*h/6;
}
    
