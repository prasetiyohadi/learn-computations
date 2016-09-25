#include <iostream>
#include <cmath>
// f(x,y) = x^3 - 10*x^2 + 29*x - 20 - y = 0
// f'(x,y) = 3*x^2 - 20*x + 29 - y' = 0
double func (double x);
double funcDer1 (double x);
int main () {
    bool loop;
    double err, x, xt;
    //xt = 0;
    //xt = 3;
    xt = 4.8;
    err = 0.00001;
    loop = true;
    while (loop) {
        x = xt - (func(xt)/funcDer1(xt));
        if (func(x) == 0) break;
        if (std::fabs(xt-x) < err) loop = false;
        xt = x;
    }

    std::cout << "root of the equation is " << x << std::endl;
}

double func (double x) {
    return std::pow(x, 3) - 10*std::pow(x, 2) + 29*x - 20;
}

double funcDer1 (double x) {
    return 3*std::pow(x, 2) - 20*x + 29;
}
