#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;
#include "sobol.hpp"

int main () {
    double y[2];
    int m, x1Max, x1Min, x2Max, x2Min;
    x2Min = -5;
    x2Max = 5;
    x1Min = -5;
    x1Max = 5;
    m = 400;
    srand(time(NULL));
    for (int i=0; i<m; i++) {
        y[0] = (double) rand()/RAND_MAX;
        y[1] = (double) rand()/RAND_MAX;
        cout << setprecision(4) 
            << y[0]*(x1Max-x1Min)+x1Min << "\t" 
            << y[1]*(x2Max-x2Min)+x2Min << "\n";
    }
    return 0;
}
