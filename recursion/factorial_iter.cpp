#include <iostream>
using namespace std;

int main() {
    int n, fact;
    cout << "input a number: ";
    cin >> n;
    if (n < 0) {
         cout << "number cannot be negative" << endl;
         return 1;
    }
    fact = 1;
    int i = n;
    while (i > 0) {
        fact = fact*i;
        i -= 1;
    }
    cout << "factorial of number " << n << " is " << fact << endl;
    return 0;
}
