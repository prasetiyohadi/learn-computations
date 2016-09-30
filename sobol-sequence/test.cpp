#include <iomanip>
#include <iostream>
using namespace std;
#include "sobol.hpp"

int main () {
    double x[2];
    int m, x1Max, x1Min, x2Max, x2Min;
    long long int seed;
    x2Min = -5;
    x2Max = 5;
    x1Min = -5;
    x1Max = 5;
    seed = 0;
    m = 400;
    for (int i=0; i<m; i++) {
        i8_sobol(2, &seed, x);
        cout << setprecision(4) 
            << x[0]*(x1Max-x1Min)+x1Min << "\t" 
            << x[1]*(x2Max-x2Min)+x2Min << "\n";
    }
    return 0;
}
