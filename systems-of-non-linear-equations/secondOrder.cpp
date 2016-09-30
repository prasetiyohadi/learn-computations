#include <iostream>
#include <cmath>
// f(x1,x2) = x1*x2 - 1 = 0
// f(x1,x2) = x1^2 + x2^2 - 4 = 0
int main () {
    double x, xMax, xMin, y;
    int N;
    N = 1000;
    xMax = 2.5;
    xMin = -2.5;
    y = 0;
    for (int i=0; i<N; i++) {
        x = xMin + i*(xMax - xMin)/N;
        if ( x != 0 )
            std::cout << x << "\t" << 1/x << "\t"; 
        // if ( x > -2 && x <= 2 )
        //     std::cout << 4 - std::pow(x, 2) << "\t"; 
        // if ( x > -2 && x <= 2 )
        //     std::cout << - 4 + std::pow(x, 2); 
        std::cout << std::endl;
    }
    return 0;
}
