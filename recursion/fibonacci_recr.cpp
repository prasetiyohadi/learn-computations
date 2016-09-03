#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n < 1) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main () {
    int n;
    cout << "input a number: ";
    cin >> n;
    int fib[n];
    if (n < 1) {
        cout << "number cannot be less than one" << endl;
        return 1;
    }
    int i = n;
    while (i > 0) {
        fib[i-1] = fibonacci(i);
        i -= 1;
    }
    cout << "fibonacci series of number " << n << " is:" << endl;
    for (int i=0; i<n; i++) {
        cout << fib[i] << " ";
    }
    cout << endl;
    return 0;
}
