#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main () {
    ofstream output;
    vector<vector<double>> a;
    vector<double> b, x, xt;
    bool loop;
    double err, tmp1, tmp2, y, z;
    int c, n;

    c = 0;
    n = 3;
    err = 0.001;
    loop = true;

    x.clear();
    for (int i=0; i<n; i++) x.push_back(0);

    /* System of linear equation
     * x1 - x2 + 2*x3 = 3.8
     * 4*x1 + 3*x2 - x3 = -5.7
     * 5*x1 + x2 + 3*x3 = 2.8
     */
    /*a = {{5, 1, 3},
        {4, 3, -1},
        {1, -1, 2}};
    b = {2.8, -5.7, 3.8};*/
    a = {{5, 1, 3},
        {4, 3, -1},
        {1, -1, 2}};
    b = {2.8, -5.7, 3.8};
    xt = {1, -1, 1};
    output.open("MidTerm4_20915301_PrasetiyoHadiPurwoko.out");

    for (int i=0; i<n; i++) output << "x" << i+1 << "\t";
    output << "error" << endl;
    for (int i=0; i<n; i++) output << xt[i] << "\t";
    output << "-" << endl;

    while (loop) {
        c += 1;
        y = 0; z = 0;
        for (int i=0; i<n; i++) {
            tmp1 = 0; tmp2 = 0;
            for (int j=0; j<i; j++) tmp1 += -1*a[i][j]*x[j];
            for (int j=i+1; j<n; j++) tmp2 += -1*a[i][j]*xt[j];
            x[i] = (tmp1+tmp2+b[i])/a[i][i];
            output << x[i] << "\t";
        }
        for (int i=0; i<n; i++)
            if (fabs(x[i] - xt[i]) > y)
                y = fabs(x[i] - xt[i]);
        for (int i=0; i<n; i++)
            if (fabs(x[i]) > z)
                z = fabs(x[i]);
        if ((y/z) < err) loop = false;
        output << y/z << endl;
        xt = x;
    }

    output << "Number of iterations: " << c << endl;
    output.close();

    return 0;
}
