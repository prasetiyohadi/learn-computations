#include <iostream>
#include <cmath>
// f(x,y) = x^3 - 10 *x^2 + 29*x - 20 - y = 0
double func (double x);
int main () {
    double a, b, c, err, x, xMax, xMin, y;
    // a = 0;
    // a = 1.1;
    a = 4.1;
    b = 6;
    y = 0;
    err = 0.00001;
    while (b-a > err) {
        c = (b+a)/2;
        if (func(c) == 0) break;
        if (func(a)*func(c) < 0) b = c;
        else a = c;
    }

    std::cout << "root of the equation is " << c << std::endl;
}

double func (double x) {
    return std::pow(x, 3) - 10*std::pow(x, 2) + 29*x - 20;
}
