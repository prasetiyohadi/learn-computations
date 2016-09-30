/* 2-Dimensial Spiral Optimization
 * step 0: preparation
 * number of search points: m >= 2
 * parameters of S2(r, tetha): 0 <= tetha < 2pi, 0 < r < 1
 * maximum iteration numbers: k_max
 * step 1: initialization
 * initial points: x_i(0) elements of R2, i = 1, 2, ..., m
 * center x* = x_{ig}(0), ig = arg min f(x_i(0)), i = 1, 2, ..., m
 * step 2: updating x_i
 * x_i(k+1) = S2(r, tetha)x_i(k) - S2(r, tetha - I2)x*, i = 1, 2, ..., m
 * step 3: updating x*
 * x* = x_{ig}(k+1), ig = arg min f(x_i(k+1)), i = 1, 2, ..., m
 * step 4: checking terminating criterion
 * if k = k_max, then terminate
 * otherwise, set k = k + 1, return to step 2
 */

#include <iostream>
#include <vector>
using namespace std;
#include "sobol.hpp"
vector<vector<double>> initializePoints(int m, int x1, int X1, int x2, 
        int X2);
vector<vector<double>> spiralOptimize(
        int m,
        vector<double>& xig,
        vector<vector<double>>& xt,
        vector<vector<double>>& s);
vector<double> argMin(vector<vector<double>>& x);
double func(vector<double>& x);
int main () {
    vector<vector<double>> x, xt;
    vector<vector<double>> s2;
    vector<double> xig;
    int K, m, x1Max, x1Min, x2Max, x2Min;
    x2Min = -5;
    x2Max = 5;
    x1Min = -5;
    x1Max = 5;
    m = 5;
    K = 50;
    s2 = {{0.67, -0.67},
        {0.67, 0.67}};
    xt = initializePoints(m, x1Min, x1Max, x2Min, x2Max);
    //xig = argMin(xt);
    xig = {0, 0};
    for (int i=0; i<K; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<2; k++)
                cout << xt[j][k] << "\t";
            //cout << endl;
        }
        cout << endl;
        x = spiralOptimize(m, xig, xt, s2);
        //xig = argMin(x);
        xt = x;
    }
    return 0;
}
vector<vector<double>> initializePoints(int m, int x1, int X1, int x2,
        int X2) {
    vector<vector<double>> x;
    vector<double> row;
    double rn[2];
    long long int seed;
    seed = 0;
    for (int i=0; i<m; i++)  {
        row.clear();
        i8_sobol(2, &seed, rn);
        row.push_back(rn[0]*(X1-x1)+x1);
        row.push_back(rn[1]*(X2-x2)+x2);
        x.push_back(row);
    }
    return x;
}
vector<vector<double>> spiralOptimize(
        int m,
        vector<double>& xig,
        vector<vector<double>>& xt,
        vector<vector<double>>& s) {
    vector<vector<double>> i2, x;
    vector<double> row;
    double tmp1, tmp2;
    i2 = {{1, 0}, {0, 1}};
    for (int i=0; i<m; i++) {
        row.clear();
        for (int j=0; j<2; j++) {
            tmp1 = 0;
            tmp2 = 0;
            for (int k=0; k<2; k++) {
                tmp1 += s[j][k]*xt[i][k];
                tmp2 += (s[j][k]-i2[j][k])*xig[k];
            }
            row.push_back(tmp1 - tmp2);
        }
        x.push_back(row);
    }
    return x;
}
vector<double> argMin(vector<vector<double>>& x) {
    double tmp;
    int xi;
    tmp = func(x.at(0));
    xi = 0;
    for (int i=1; i<x.size(); i++)
        if (func(x.at(i)) < tmp) {
            tmp = func(x.at(i));
            xi = i;
        }
    return x.at(xi);
}
double func(vector<double>& x) {
    return 0.0;
}
