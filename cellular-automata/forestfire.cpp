#include <iostream>
using namespace std;

class Tree {
        int state;
        float probability, next_probability;
    public:
        Tree () { 
            state = 0; 
            probability = 0.0;
        }
        Tree (int s) {
            state = s; 
            probability = 0.0;
        }
        int get_state() { return state; }
        float get_probability() { return probability; }
        float get_next_probability() { return next_probability; }
        float get_contribution() { 
            switch(state) {
                case 0:
                    return 0.0;
                    break;
                case 1:
                    return 1.0;
                    break;
                case 2:
                    return 0.0;
                    break;
                default:
                    return 0.0;
            }
        }
        void set_state(int s) { state = s; }
        void set_probability(float p) { 
            if (p > 3.0 && p < 9.0) { state = 1; probability = p; }
            else if (p > 9.0) { state = 2; probability = 9.0; }
            else probability = p;
        }
        void set_next_probability(float p) { next_probability = probability + p; }
};

class Environment {
        float kernel[3][3];
        int wind;
    public:
        Environment() { 
            kernel[0][0] = 0.83; kernel[0][1] = 1.0; kernel [0][2] = 0.83;
            kernel[1][0] = 1.00; kernel[1][1] = 1.0; kernel [1][2] = 1.00;
            kernel[2][0] = 0.83; kernel[2][1] = 1.0; kernel [2][2] = 0.83;
            wind = 0;
        }
        int get_wind() { return wind; }
        float get_kernel(int a, int b) {
            return kernel[a][b];
        }
        float get_kernel(int a, int b, int c, int d, int e) {
            if (a == 0 && b == 0) {
                if (c == 0 && d == 0) return 0.0;
                else if (c == 0 && d == 1) return 0.0;
                else if (c == 0 && d == 2) return 0.0;
                else if (c == 1 && d == 0) return 0.0;
                else if (c == 2 && d == 0) return 0.0;
                else return kernel[c][d];
            }
            else if (a == 0 && b == e) {
                if (c == 0 && d == 0) return 0.0;
                else if (c == 0 && d == 1) return 0.0;
                else if (c == 0 && d == 2) return 0.0;
                else if (c == 1 && d == 2) return 0.0;
                else if (c == 2 && d == 2) return 0.0;
                else return kernel[c][d];
            }
            else if (a == e && b == 0) {
                if (c == 0 && d == 0) return 0.0;
                else if (c == 1 && d == 0) return 0.0;
                else if (c == 2 && d == 0) return 0.0;
                else if (c == 2 && d == 1) return 0.0;
                else if (c == 2 && d == 2) return 0.0;
                else return kernel[c][d];
            }
            else if (a == e && b == e) {
                if (c == 0 && d == 2) return 0.0;
                else if (c == 1 && d == 2) return 0.0;
                else if (c == 2 && d == 2) return 0.0;
                else if (c == 2 && d == 1) return 0.0;
                else if (c == 2 && d == 0) return 0.0;
                else return kernel[c][d];
            }
            else if (a == 0 && (b != 0 || b != e)) {
                if (c == 0 && d == 0) return 0.0;
                else if (c == 0 && d == 1) return 0.0;
                else if (c == 0 && d == 2) return 0.0;
                else return kernel[c][d];
            }
            else if (a == e && (b != 0 || b != e)) {
                if (c == 2 && d == 0) return 0.0;
                else if (c == 2 && d == 1) return 0.0;
                else if (c == 2 && d == 2) return 0.0;
                else return kernel[c][d];
            }
            else if ((a != 0 || a != e) && b == 0) {
                if (c == 0 && d == 0) return 0.0;
                else if (c == 1 && d == 0) return 0.0;
                else if (c == 2 && d == 0) return 0.0;
                else return kernel[c][d];
            }
            else if ((a != 0 || a != e) && b == e) {
                if (c == 0 && d == 2) return 0.0;
                else if (c == 1 && d == 2) return 0.0;
                else if (c == 2 && d == 2) return 0.0;
                else return kernel[c][d];
            }
            else return kernel[c][d];
        }
        void set_wind(int d, int w) {
            if (w == 1) {
                switch(d) {
                    case 1:
                        wind = 1;
                        kernel[0][0] = 0.8300; kernel[0][1] = 0.9; kernel [0][2] = 0.8300;
                        kernel[1][0] = 1.0000; kernel[1][1] = 1.0; kernel [1][2] = 1.0000;
                        kernel[2][0] = 0.8632; kernel[2][1] = 1.1; kernel [2][2] = 0.8632;
                        break;
                    case 2:
                        wind = 2;
                        kernel[0][0] = 0.8632; kernel[0][1] = 1.0; kernel [0][2] = 0.8300;
                        kernel[1][0] = 1.1000; kernel[1][1] = 1.0; kernel [1][2] = 0.9000;
                        kernel[2][0] = 0.8632; kernel[2][1] = 1.0; kernel [2][2] = 0.8300;
                        break;
                    case 3:
                        wind = 3;
                        kernel[0][0] = 0.8632; kernel[0][1] = 1.1; kernel [0][2] = 0.8632;
                        kernel[1][0] = 1.0000; kernel[1][1] = 1.0; kernel [1][2] = 1.0000;
                        kernel[2][0] = 0.8300; kernel[2][1] = 0.9; kernel [2][2] = 0.8300;
                        break;
                    case 4:
                        wind = 4;
                        kernel[0][0] = 0.8300; kernel[0][1] = 1.0; kernel [0][2] = 0.8632;
                        kernel[1][0] = 0.9000; kernel[1][1] = 1.0; kernel [1][2] = 1.1000;
                        kernel[2][0] = 0.8300; kernel[2][1] = 1.0; kernel [2][2] = 0.8632;
                        break;
                    default:
                        wind = 0;
                }
            } else if (w == 2) {
                switch(d) {
                    case 1:
                        wind = 1;
                        kernel[0][0] = 0.830; kernel[0][1] = 0.8; kernel [0][2] = 0.830;
                        kernel[1][0] = 1.000; kernel[1][1] = 1.0; kernel [1][2] = 1.000;
                        kernel[2][0] = 0.913; kernel[2][1] = 1.3; kernel [2][2] = 0.913;
                        break;
                    case 2:
                        wind = 2;
                        kernel[0][0] = 0.913; kernel[0][1] = 1.0; kernel [0][2] = 0.83;
                        kernel[1][0] = 1.300; kernel[1][1] = 1.0; kernel [1][2] = 0.80;
                        kernel[2][0] = 0.913; kernel[2][1] = 1.0; kernel [2][2] = 0.83;
                        break;
                    case 3:
                        wind = 3;
                        kernel[0][0] = 0.913; kernel[0][1] = 1.3; kernel [0][2] = 0.913;
                        kernel[1][0] = 1.000; kernel[1][1] = 1.0; kernel [1][2] = 1.000;
                        kernel[2][0] = 0.830; kernel[2][1] = 0.8; kernel [2][2] = 0.830;
                        break;
                    case 4:
                        wind = 4;
                        kernel[0][0] = 0.83; kernel[0][1] = 1.0; kernel [0][2] = 0.913;
                        kernel[1][0] = 0.80; kernel[1][1] = 1.0; kernel [1][2] = 1.300;
                        kernel[2][0] = 0.83; kernel[2][1] = 1.0; kernel [2][2] = 0.913;
                        break;
                    default:
                        wind = 0;
                }
            }
        }
};

int main () {
    const int length = 31;
    int iter = 1, count1 = 0, count2 = 0;
    float sum;
    Tree trees[length][length];
    trees[16][16].set_state(1);
    Environment env;
    //env.set_wind(3, 1);

    cout << "Kernel" << endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) 
            cout << env.get_kernel(i, j) << " ";
        cout << endl;
    }

    cout << "initial state" << " ( wind: " << env.get_wind() << " )" << endl;
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) {
            cout << trees[i][j].get_state() << " ";
            //cout << trees[i][j].get_probability() << " ";
            if (trees[i][j].get_state() == 2) count2 += 1;
            else if (trees[i][j].get_state() == 1) count1 += 1;
        }
        cout << endl;
    }
    cout << "pohon hangus: " << count2 << ", terbakar: " << count1 << ", hidup : " << length*length - (count1 + count2) << endl;

    do {
        cout << "iterasi ke: " << iter << " ( wind: " << env.get_wind() << " )" << endl;

        for (int i=0; i<length; i++) {
            for (int j=0; j<length; j++) {
                sum = 0;
                for (int m=0; m<3; m++) {
                    for (int n=0; n<3; n++) {
                        sum += trees[i+(m-1)][j+(n-1)].get_contribution()*env.get_kernel(i, j, m, n, length-1);
                    }
                }
                trees[i][j].set_next_probability(sum);
            }
        }

        for (int i=0; i<length; i++)  
            for (int j=0; j<length; j++) 
                trees[i][j].set_probability(trees[i][j].get_next_probability());

        count1 = 0; count2 = 0;
        for (int i=0; i<length; i++) { 
            for (int j=0; j<length; j++) {
                cout << trees[i][j].get_state() << " ";
                //cout << trees[i][j].get_probability() << " ";
                if (trees[i][j].get_state() == 2) count2 += 1;
                else if (trees[i][j].get_state() == 1) count1 += 1;
            }
            cout << endl;
        }
        cout << "pohon hangus: " << count2 << ", terbakar: " << count1 << ", hidup : " << length*length - (count1 + count2) << endl;
        iter += 1;

    } while (count2 < (0.5*length*length));

    return 0;
}
