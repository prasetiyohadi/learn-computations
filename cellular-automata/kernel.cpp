#include <iostream>
using namespace std;

class Kernel {
        int kernel[3][3];
    public:
        Kernel() { 
            for (int i=0; i<3; i++)
                for (int j=0; j<3; j++)
                    kernel[i][j] = 2;
        }
        int get_kernel(int i, int j) { return kernel[i][j]; }
};

int main () {
    int mykernel[3][3];
    Kernel kernel;
    for (int i=0; i<3; i++) 
        for (int j=0; j<3; j++) 
            mykernel[i][j] = kernel.get_kernel(i, j);
    cout << endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            cout << mykernel[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
