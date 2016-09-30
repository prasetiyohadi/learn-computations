#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<vector<double>> a;
    vector<double> b, x, xt;
    bool loop;
    double err, tmp, y, z;
    int c, n;

    c = 0;
    n = 3;
    err = 0.001;
    loop = true;

    x.clear();
    for (int i=0; i<n; i++) x.push_back(0);

    a = {{4, -1, 1},
        {4, -8, 1},
        {-2, 1, 5}};
    b = {7, -21, 15};
    xt = {1, 2, 2};

    for (int i=0; i<n; i++) cout << "x" << i+1 << "\t";
    cout << "error" << endl;
    for (int i=0; i<n; i++) cout << xt[i] << "\t";
    cout << "-" << endl;

    while (loop) {
        c += 1;
        y = 0; z = 0;
        for (int i=0; i<n; i++) {
            tmp = 0;
            for (int j=0; j<n; j++) {
                if (i != j) tmp += -1*a[i][j]*xt[j];
            }
            x[i] = (tmp+b[i])/a[i][i];
            cout << x[i] << "\t";
        }
        for (int i=0; i<n; i++)
            if (fabs(x[i] - xt[i]) > y)
                y = fabs(x[i] - xt[i]);
        for (int i=0; i<n; i++)
            if (fabs(x[i]) > z)
                z = fabs(x[i]);
        if ((y/z) < err) loop = false;
        cout << y/z << endl;
        xt = x;
    }

    cout << "Number of iterations: " << c << endl;

    return 0;
}
