#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<double> jacobi (int n, 
        vector<double>& ii, 
        vector<double>& jj, 
        vector<double>& bb, 
        vector<vector<double>>& aa) {
    double tmp;
    for (int i=0; i<n; i++) {
        tmp = 0;
        for (int j=0; j<n; j++) if (i != j) tmp += -1*aa[i][j]*jj[j];
        ii[i] = (tmp+bb[i])/aa[i][i];
    }
    return ii;
}

vector<double> gaussSeidel (int n, 
        vector<double>& ii, 
        vector<double>& jj, 
        vector<double>& bb, 
        vector<vector<double>>& aa) {
    double tmp1, tmp2;
    for (int i=0; i<n; i++) {
        tmp1 = 0; tmp2 = 0;
        for (int j=0; j<i; j++) tmp1 += -1*aa[i][j]*ii[j];
        for (int j=i+1; j<n; j++) tmp2 += -1*aa[i][j]*jj[j];
        ii[i] = (tmp1+tmp2+bb[i])/aa[i][i];
    }
    return ii;
}

double error (vector<double>& ii, vector<double>& jj) {
    double y = 0, z = 0;
    int n = ii.size();
    for (int i=0; i<n; i++)
        if (fabs(ii[i] - jj[i]) > y)
            y = fabs(ii[i] - jj[i]);
    for (int i=0; i<n; i++)
        if (fabs(ii[i]) > z)
            z = fabs(ii[i]);
    return y/z;
}

int main () {
    vector<vector<double>> a;
    vector<double> b, r, x, xt;
    bool loop;
    double err, v;
    int c, n, s;

    cout << "info: program to calculate solution of systems of linear \
equations Ax = b iteratively" << endl;
    cout << "select iterative method [1:jacobi, 2:gaussSeidel]: ";
    cin >> s;
    cout << "input tolerance value: ";
    cin >> err;
    cout << "input the number of unknown variables (length of vector x): ";
    cin >> n;
    cout << "input matrix A in tabularized form: " << endl;
    for (int i=0; i<n; i++) {
        r.clear();
        for (int j=0; j<n; j++) {
            cin >> v;
            r.push_back(v);
        }
        a.push_back(r);
    }
    cout << "input vector b in transpose form: " << endl;
    for (int i=0; i<n; i++) {
        cin >> v;
        b.push_back(v);
    }
    cout << "input initial value of vector x in transpose form: " << endl;
    for (int i=0; i<n; i++) {
        cin >> v;
        xt.push_back(v);
    }

    c = 0;
    loop = true;

    x.clear();
    for (int i=0; i<n; i++) x.push_back(0);

    for (int i=0; i<n; i++) cout << "x" << i+1 << "\t";
    cout << "error" << endl;
    for (int i=0; i<n; i++) cout << xt[i] << "\t";
    cout << "-" << endl;

    while (loop) {
        c += 1;
        if (s == 1) x = jacobi(n, x, xt, b, a);
        else if (s == 2 ) x = gaussSeidel(n, x, xt, b, a);
        else {
            cout << "wrong input" << endl;
            return 1;
        }
        for (int i=0; i<n; i++) cout << x[i] << "\t";
        if (error(x, xt) < err) loop = false;
        cout << error(x, xt) << endl;
        xt = x;
    }

    cout << "Number of iterations: " << c << endl;

    return 0;
}
