#include <iostream>
using namespace std;

int main() {
    int n, move;
    cout << "input a number: ";
    cin >> n;
    if (n < 0) {
         cout << "number cannot be negative" << endl;
         return 1;
    } 
    else if (n == 1) {
        cout << "number of moves to solve tower of hanoi problems with 1 piece of pegs is: 1" << endl;
    }
    else {      
        move = 1;
        int i = n;
        while (i > 1) {
            move = 2*move+1;
            i -= 1;
        }
        cout << "number of moves to solve tower of hanoi problems with " 
            << n << " piece of pegs is: " << move << endl;
    }
    return 0;
}
