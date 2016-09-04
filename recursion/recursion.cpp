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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}

int towerofhanoi(int n) {
    if (n < 1) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return 2*towerofhanoi(n-1)+1;
    }
}

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
    int a, b, n, fact, gcdv, move, select;
    cout << "select a program [1:factorial, 2:gcd, 3:towerofhanoi, " 
        << "4:fibonacci]: ";
    cin >> select;
    if (select == 1) {
        cout << "input a number: ";
        cin >> n;
        if (n < 0) {
            cout << "number cannot be negative" << endl;
            return 1;
        }
        fact = factorial(n);
        cout << "factorial of number " << n << " is " << fact << endl;
    }
    else if (select == 2) {
        cout << "input first number: ";
        cin >> a;
        cout << "input second number: ";
        cin >> b;
        if (a < 0 || b < 0) {
            cout << "number cannot be negative" << endl;
            return 1;
        }
        gcdv = gcd(a, b);
        cout << "greatest common divisor of " << a << " and " << b << " is " << 
            gcdv << endl;
    }
    else if (select == 3) {
        cout << "input a number: ";
        cin >> n;
        if (n < 1) {
            cout << "number cannot be less than one" << endl;
            return 1;
        }
        move = towerofhanoi(n);
        cout << "number of moves to solve tower of hanoi problems with " 
            << n << " piece of pegs is: " << move << endl;
    }
    else if (select == 4) {
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
        cout << "first " << n << " numbers of fibonacci series is:" << endl;
        for (int i=0; i<n; i++) {
            cout << fib[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "wrong input, terminating..." << endl;
        return 1;
    }
    return 0;
}
