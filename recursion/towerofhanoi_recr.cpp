#include <iostream>
using namespace std;

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

int main () {
    int n, move;
    cout << "input a number: ";
    cin >> n;
    if (n < 1) {
        cout << "number cannot be less than one" << endl;
        return 1;
    }
    move = towerofhanoi(n);
    cout << "number of moves to solve tower of hanoi problems with " 
        << n << " piece of pegs is: " << move << endl;
    return 0;
}
