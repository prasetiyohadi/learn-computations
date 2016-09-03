#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}

int main () {
    int a, b, gcdv;
    cout << "input first number: ";
    cin >> a;
    cout << "input second number: ";
    cin >> b;
    if (a < 0 || b < 0) {
        cout << "number cannot be negative" << endl;
        return 1;
    }
    gcdv = gcd(a, b);
    cout << "greatest common divisor of " << a << " and " << b << " is " << gcdv << endl;
    return 0;
}
