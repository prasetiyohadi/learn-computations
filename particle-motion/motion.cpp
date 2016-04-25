#include <iostream>
#include <cmath>
using namespace std;

int main () {
    float x = 3.0, y = 2.0, xt, yt;
    float vx = 0.1, vy = -1.0, vxt, vyt;
    float theta0 = atan(vy/vx), thetat, alpha1 = 0.927, alpha2 = 2.214;
    float dt = 0.1, time;
    float T1[2][2] = {{cos(2.0*alpha1), sin(2.0*alpha1)}, {sin(2.0*alpha1), -cos(2.0*alpha1)}};
    float T2[2][2] = {{cos(2.0*alpha2), sin(2.0*alpha2)}, {sin(2.0*alpha2), -cos(2.0*alpha2)}};
    cout << "time" << "\t" << "x" << "\t" << "y" << "\t" << "vx" << "\t" << "vy" << "\t" << "theta" << endl;
    cout << "0" << "\t" << x << "\t" << y << "\t" << vx << "\t" << vy << "\t" << theta0 << endl;
    //cout << "x" << "\t" << "y" << endl;
    //cout << x << "\t" << y << endl;
    do {
        x = x + vx*dt;
        y = y + vy*dt;
        xt = x;
        yt = y;
        vxt = vx;
        vyt = vy;
        thetat = theta0;
        if (y > 4.0*x/3.0) {
            theta0 = 2*M_PI + 2.0*alpha1 - thetat;
            vx = sqrt(pow(vxt, 2.0) + pow(vyt, 2.0))*cos(theta0);
            vy = sqrt(pow(vxt, 2.0) + pow(vyt, 2.0))*sin(theta0);
            x = T1[0][0]*xt + T1[0][1]*yt;
            y = T1[1][0]*xt + T2[1][1]*yt;
        } 
        if (y > -4.0*x/3.0+8.0) {
            theta0 = 2.0*M_PI + 2.0*alpha2 - thetat;
            vx = sqrt(pow(vxt, 2.0) + pow(vyt, 2.0))*cos(theta0);
            vy = sqrt(pow(vxt, 2.0) + pow(vyt, 2.0))*sin(theta0);
            x = T2[0][0]*xt + T2[0][1]*(yt-8.0);
            y = T2[1][0]*xt + T2[1][1]*(yt-8.0) + 8.0;
        } 
        if (y < 0.0) {
            theta0 = 2.0*M_PI - thetat;
            vx = sqrt(pow(vxt, 2.0) + pow(vyt, 2.0))*cos(theta0);
            vy = sqrt(pow(vxt, 2.0) + pow(vyt, 2.0))*sin(theta0);
            x = xt;
            y = -yt;
        }
        time += dt;
        cout << time << "\t" << x << "\t" << y << "\t" << vx << "\t" << vy << "\t" << theta0 << endl;
        //cout << x << "\t" << y << endl;
    } while (time < 15.0);
    return 0;
}
