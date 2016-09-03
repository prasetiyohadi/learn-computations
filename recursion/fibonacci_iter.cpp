#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input a number: ";
    cin >> n;
    if (n < 1) {
         cout << "number cannot be less than one" << endl;
         return 1;
    }
    else if (n == 1) {
        cout << "fibonacci series of number 1 is:" << endl;
        cout << "1" << endl;
    }
    else if (n == 2) {
        cout << "fibonacci series of number 2 is:" << endl;
        cout << "1 1" << endl;
    }
    else {
        int fib[n];
        fib[0] = 1;
        fib[1] = 1;
        int i = 2;
        while (i < n+2) {
            fib[i] = fib[i-1] + fib[i-2];
            i += 1;
        }
        cout << "fibonacci series of number " << n << " is:" << endl;
        for (int i=0; i<n; i++) {
            cout << fib[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
