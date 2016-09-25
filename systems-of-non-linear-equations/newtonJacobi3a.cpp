#include <cmath>
#include <iostream>
#include <vector>
// f1(x1,x2) = 0.5*sin(x1*x2) - 0.25*x2/pi - 0.5*x1 = 0
// df1(x1,x2)/dx1 = 0.5*x2*cos(x1*x2) - 0.5
// df1(x1,x2)/dx2 = 0.5*x1*cos(x1*x2) - 0.25/pi
// f2(x1,x2) = (1-0.25/pi)*(e^(2*x1)-e) + e*x2/pi - 2*e*x1 = 0
// df2(x1,x2)/dx1 = (1-0.25/pi)*(2*e^(2*x1)) - 2*e
// df2(x1,x2)/dx2 = e/pi
double func1 (double x1, double x2);
double func2 (double x1, double x2);
double error (std::vector<double>& ii, std::vector<double>& jj);
std::vector<double> jacobi (int n, 
        std::vector<double>& ii, 
        std::vector<double>& jj, 
        std::vector<double>& bb, 
        std::vector<std::vector<double>>& aa);
std::vector<double> gaussSeidel (int n, 
        std::vector<double>& ii, 
        std::vector<double>& jj, 
        std::vector<double>& bb, 
        std::vector<std::vector<double>>& aa);
int main () {
    std::vector<std::vector<double>> a;
    std::vector<double> b, dx, dxt, x, xt;
    bool loop1, loop2;
    double err;
    int c, d;
    c = 0;
    err = 0.00001;
    loop1 = true;
    loop2 = true;
    x = {0, 0};
    xt = {0.7, 1.1};
    while (loop1) {
        loop2 = true;
        a = {{0.5*xt[1]*std::cos(xt[0]*xt[1])-0.5, 
            0.5*xt[0]*std::cos(xt[0]*xt[1])-0.25/M_PI}, 
            {(1-0.25/M_PI)*2*std::exp(2*xt[0])-2*std::exp(1), 
            std::exp(1)/M_PI}};
        b = {-1*func1(xt[0], xt[1]), -1*func2(xt[0], xt[1])};
        dx = {0, 0};
        dxt = {0, 0};
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) std::cout << a[i][j] << "\t";
            std::cout << std::endl;
        }
        for (int i=0; i<2; i++) std::cout << b[i] << "\t";
        std::cout << std::endl;
        d = 0;
        while (loop2) {
            //dx = jacobi(2, dx, dxt, b, a);
            dx = gaussSeidel(2, dx, dxt, b, a);
            for (int i=0; i<2; i++) std::cout << dx[i] << "\t";
            if (error(dx, dxt) < err) loop2 = false;
            std::cout << error(dx, dxt) << std::endl;
            dxt = dx;
            d += 1;
            //if (d > 10) break;
            //break;
        }
        std::cout << "inner loop finished" << std::endl;
        for (int i=0; i<2; i++) x[i] = xt[i] + dx[i];
        for (int i=0; i<2; i++) std::cout << xt[i] << "\t";
        for (int i=0; i<2; i++) std::cout << x[i] << "\t";
        if (func1(x[0], x[1]) == 0 && func2(x[0], x[1]) == 0) break;
        if (error(x, xt) < err) loop1 = false;
        std::cout << error(x, xt) << std::endl;
        xt = x;
        c += 1;
        std::cout << "outer loop: " << c << std::endl;
        if (c > 10) break;
        //break;
    }

    std::cout << "root of the equation is:" << std::endl;
    for (int i=0; i<2; i++) std::cout << x[i] << "\t";
    std::cout << std::endl;

    return 0;
}
// f1(x1,x2) = 0.5*sin(x1*x2) - 0.25*x2/pi - 0.5*x1 = 0
// df1(x1,x2)/dx1 = 0.5*x2*cos(x1*x2) - 0.5
// df1(x1,x2)/dx2 = 0.5*x1*cos(x1*x2) - 0.25/pi
// f2(x1,x2) = (1-0.25/pi)*(e^(2*x1)-e) + e*x2/pi - 2*e*x1 = 0
// df2(x1,x2)/dx1 = (1-0.25/pi)*(2*e^(2*x1)) - 2*e
// df2(x1,x2)/dx2 = e/pi
double func1 (double x1, double x2) {
    //return std::pow(x1, 2) + std::pow(x2, 2) - 4;
    //return std::exp(x1-x2) - std::sin(x1+x2);
    return 0.5*std::sin(x1*x2) - 0.25*x2/M_PI - 0.5*x1;
}
double func2 (double x1, double x2) {
    //return x1*x2 - 1;
    //return std::pow(x1, 2)*std::pow(x2, 2) - std::cos(x1+x2);
    return (1-0.25/M_PI)*(std::exp(2*x1) - std::exp(1)) + std::exp(1)*x2/M_PI 
        - 2*std::exp(1)*x1;
}
double error (std::vector<double>& ii, std::vector<double>& jj) {
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
std::vector<double> jacobi (int n, 
        std::vector<double>& ii, 
        std::vector<double>& jj, 
        std::vector<double>& bb, 
        std::vector<std::vector<double>>& aa) {
    double tmp;
    for (int i=0; i<n; i++) {
        tmp = 0;
        for (int j=0; j<n; j++) if (i != j) tmp += -1*aa[i][j]*jj[j];
        ii[i] = (tmp+bb[i])/aa[i][i];
    }
    return ii;
}
std::vector<double> gaussSeidel (int n, 
        std::vector<double>& ii, 
        std::vector<double>& jj, 
        std::vector<double>& bb, 
        std::vector<std::vector<double>>& aa) {
    double tmp1, tmp2;
    for (int i=0; i<n; i++) {
        tmp1 = 0; tmp2 = 0;
        for (int j=0; j<i; j++) tmp1 += -1*aa[i][j]*ii[j];
        for (int j=i+1; j<n; j++) tmp2 += -1*aa[i][j]*jj[j];
        ii[i] = (tmp1+tmp2+bb[i])/aa[i][i];
    }
    return ii;
}
