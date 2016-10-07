#include <fstream>
#include <iostream>
#include <cmath>
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
vector<double> argMax(vector<vector<double>>& x);
double func(vector<double>& x);
int main () {
    ofstream output;
    vector<vector<double>> x, xt;
    vector<vector<double>> s2;
    vector<double> xig;
    int K, m, x1Max, x1Min, x2Max, x2Min;
    x2Min = -3;
    x2Max = 3;
    x1Min = -3;
    x1Max = 3;
    m = 200;
    K = 100;
    s2 = {{0.67, -0.67},
        {0.67, 0.67}};
    xt = initializePoints(m, x1Min, x1Max, x2Min, x2Max);
    //xig = argMin(xt);
    xig = argMax(xt);
    cout << func(xig) << endl;
    //xig = {0, 0};
    output.open ("spiralOptimization2d.dat");
    for (int i=0; i<K; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<2; k++)
                output << xt[j][k] << "\t";
            output << endl;
        }
        //output << endl;
        x = spiralOptimize(m, xig, xt, s2);
        //xig = argMin(x);
        xig = argMax(x);
        cout << func(xig) << endl;
        xt = x;
    }
    cout << "the root of equations is: ";
    for (int i=0; i<2; i++) cout << xig[i] << " ";
    cout << endl;
    output.close();
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
    for (int i=1; i<x.size(); i++) {
        if (func(x.at(i)) < tmp) {
            tmp = func(x.at(i));
            xi = i;
        }
    }
    return x.at(xi);
}
vector<double> argMax(vector<vector<double>>& x) {
    double tmp;
    int xi;
    tmp = func(x.at(0));
    xi = 0;
    for (int i=1; i<x.size(); i++) {
        if (func(x.at(i)) > tmp) {
            tmp = func(x.at(i));
            xi = i;
        }
    }
    return x.at(xi);
}
double func(vector<double>& x) {
    double f1, f2;
    f1 = pow(x[0], 2) + pow(x[1], 2) - 4;
    f2 = x[0]*x[1] - 1;
    //f1 = exp(x[0]-x[1]) - sin(x[0]+x[1]);
    //f2 = pow(x[0],2)*pow(x[1],2) - cos(x[0]+x[1]);
    //f1 = 0.5*sin(x[0]*x[1]) - 0.25*x[1]/M_PI - 0.5*x[0];
    //f2 = (1-0.25/M_PI)*(exp(2*x[0]) - exp(1)) + exp(1)*x[1]/M_PI - 
    //    2*exp(1)*x[0];
    return 1/(1+fabs(f1)+fabs(f2));
}
