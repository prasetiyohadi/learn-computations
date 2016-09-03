#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}

int main () {
    int n, fact;
    cout << "input a number: ";
    cin >> n;
    if (n < 0) {
         cout << "number cannot be negative" << endl;
         return 1;
    }
    fact = factorial(n);
    cout << "factorial of number " << n << " is " << fact << endl;
    return 0;
}
