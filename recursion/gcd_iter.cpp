#include <iostream>
using namespace std;

int main () {
    int a, b, i, j, gcdv, rem, tmp;
    cout << "input first number: ";
    cin >> a;
    cout << "input second number: ";
    cin >> b;
    if (a < 0 || b < 0) {
        cout << "number cannot be negative" << endl;
        return 1;
    }
    i = a;
    j = b;
    while (j > 0) {
        rem = i%j;
        i = j;
        j = rem;
    }
    gcdv = i;
    cout << "greatest common divisor of " << a << " and " << b << " is " << gcdv << endl;
    return 0;
}
