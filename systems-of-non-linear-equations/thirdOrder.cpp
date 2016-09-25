#include <iostream>
#include <cmath>
// f(x,y) = x^3 - 10*x^2 _+ 29*x - 20 - y = 0
int main () {
    double x, xMax, xMin, y;
    int N;
    N = 1000;
    xMax = 6;
    xMin = 0;
    y = 0;
    for (int i=0; i<N; i++) {
        x = xMin + i*(xMax - xMin)/N;
        std::cout << x << "\t" << std::pow(x, 3) - 10*std::pow(x, 2) + 
            29*x - 20 << std::endl;
    }
    return 0;
}
