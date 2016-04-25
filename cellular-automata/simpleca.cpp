#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Cell {
        int state, prev_state, next_state;
        string state_to_string(int s);
    public:
        Cell () { state = 1; prev_state = 2; }
        Cell (int s) { state = s; prev_state = 2; }
        int get_raw_state() { return state; }
        string get_state();
        string get_prev_state();
        void set_state(int s);
        void set_next_state(int s) { next_state = s; }
        int get_raw_next_state() { return next_state; }
};

string Cell::state_to_string(int s) {
    switch (s) {
        case 0:
            return "dead";
            //return "x";
            break;
        case 1:
            return "alive";
            //return "o";
            break;
        default:
            return "unknown";
    }
}

string Cell::get_state() {
    int s = state;
    return state_to_string(s);
}

string Cell::get_prev_state() {
    int s = prev_state;
    return state_to_string(s);
}

void Cell::set_state(int s) {
    prev_state = state;
    state = s;
}


int ** allocate_array(int row_dim, int col_dim);
int ** state_generation(int ** cell, int row_dim, int col_dim, int ** new_cell);

int main () {
    int iter = 10;
    int new_cell[20];
    //int cell[20] = { 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0 };
    int cell[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    int length = (int)sizeof(cell)/sizeof(*cell);
    cout << length << endl << endl;

    for (int i=0; i<length; i++) cout << cell[i] << " ";
    cout << endl;

    int cell_2d[length][length], new_cell_2d[length][length], sum;
    for (int i=0; i<length; i++)
        for (int j=0; j<length; j++)
            cell_2d[i][j] = 1;

    cell_2d[length/2-1][length/2] = 0;
    cell_2d[length/2+1][length/2] = 0;
    cell_2d[length/2][length/2-1] = 0;
    cell_2d[length/2][length/2+1] = 0;

    for (int i=0; i<length; i++) { 
        for (int j=0; j<length; j++) 
            cout << cell_2d[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    int kernel[3][3] = {{ 1, 1, 1 }, { 1, 1, 1}, { 1, 1, 1}};

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            cout << kernel[i][j];
        cout << endl;
    }
    cout << endl;

    for (int k=0; k<2; k++) {
        for (int i=1; i<length-1; i++) {
            new_cell[i] = cell[i-1] & cell[i] & cell[i+1];
        }

        for (int i=1; i<length-1; i++) cell[i] = new_cell[i];
        for (int i=0; i<length; i++) cout << cell[i] << " ";
        cout << endl;
    }

    cout << endl;

    for (int a=0; a<2; a++) {
        for (int i=1; i<length-1; i++)  
            for (int j=1; j<length-1; j++) {
                sum = 0;
                for (int m=0; m<3; m++) 
                    for (int n=0; n<3; n++) 
                        sum += cell_2d[i+(m-1)][j+(n-1)]*kernel[m][n];
                if (sum < 7) new_cell_2d[i][j] = 0;
                else new_cell_2d[i][j] = 1;
            }

        for (int i=1; i<length-1; i++)  
            for (int j=1; j<length-1; j++) 
                cell_2d[i][j] = new_cell_2d[i][j];

        for (int i=0; i<length; i++) { 
            for (int j=0; j<length; j++) 
                cout << cell_2d[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    Cell mycell(1);
    cout<< mycell.get_state() << endl;
    cout<< mycell.get_prev_state() << endl;
    mycell.set_state(0);
    cout<< mycell.get_state() << endl;
    cout<< mycell.get_prev_state() << endl;
    mycell.set_state(1);
    cout<< mycell.get_state() << endl;
    cout<< mycell.get_prev_state() << endl;

    int cell_length = 10;
    Cell arr_cell[cell_length][cell_length];

    arr_cell[cell_length/2-1][cell_length/2].set_state(0);
    arr_cell[cell_length/2+1][cell_length/2].set_state(0);
    arr_cell[cell_length/2][cell_length/2-1].set_state(0);
    arr_cell[cell_length/2][cell_length/2+1].set_state(0);

    cout << endl << endl << endl;
    cout << "initial state" << endl;

    for (int i=0; i<cell_length; i++) {
        for (int j=0; j<cell_length; j++) 
            cout << arr_cell[i][j].get_state() << "\t";
        cout << endl;
    }

    cout << endl << endl;

    for (int a=0; a<3; a++) {
        cout << "iterasi ke: " << a+1 << endl;
        for (int i=1; i<cell_length-1; i++)  
            for (int j=1; j<cell_length-1; j++) {
                sum = 0;
                for (int m=0; m<3; m++) 
                    for (int n=0; n<3; n++) 
                        sum += arr_cell[i+(m-1)][j+(n-1)].get_raw_state()*kernel[m][n];
                if (sum <= 6) arr_cell[i][j].set_next_state(0);
                else arr_cell[i][j].set_next_state(1);
            }

        for (int i=1; i<cell_length-1; i++)  
            for (int j=1; j<cell_length-1; j++) 
                arr_cell[i][j].set_state(arr_cell[i][j].get_raw_next_state());

        for (int i=0; i<cell_length; i++) { 
            for (int j=0; j<cell_length; j++) 
                cout << arr_cell[i][j].get_state() << "\t";
            cout << endl;
        }
        cout << endl << endl;
    }

    return 0;
}

int ** allocate_array(int row_dim, int col_dim) {
    int ** result;

    result = (int **)malloc(row_dim*sizeof(int *));
    result[0] = (int *)malloc(row_dim*col_dim*sizeof(int));
    for (int i=1; i<row_dim; i++) result[i] = result[i-1] + col_dim;

    return result;
}
