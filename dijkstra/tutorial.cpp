#include <iostream>
#include <vector>
// macros
#define lli long long int
#define veci vector <int>
#define vecb vector <bool>
using namespace std;

int main() {
    lli n;
    cout << "Please input the number of nodes int the graph: " << endl;
    cin >> n;
    vector <veci> matrix;
    cout << "Calculate distance from which node? (e.g. source=0, first \
node=1 and so on...)" << endl;
    lli src;
    cin >> src;
    veci dist;  // respective distances of every node from your desired source
    vecb visit;     // kep track of the nodes that you have visited
    lli nxtNode;    // which node to visit next
    lli min=999999999;

    dist.clear();
    visit.clear();
    for (int i=0; i<n; i++) {
        dist.push_back(0);
        visit.push_back(false);
    }

    cout << "Please input matrix in a tabularized form" << endl;

    for (int y=0; y<n; y++) {
        veci row;
        row.clear();
        for (int r=0; r<n; r++) {
            lli d;
            cin >> d;
            row.push_back(d);
        }
        matrix.push_back(row);
    }

    dist = matrix.at(src);

    dist.at(src) = 0;
    visit.at(src) = true;

    for (int i=0; i<n; i++) {
        min = 9999999999;
        for (int h=0; h<n; h++) {
            if (min >= dist.at(h) && !visit.at(h)) {
                min = dist.at(h);
                nxtNode = h;
            }
        }
        visit.at(nxtNode) = true;
        for (int s=0; s<n; s++) {
            if (!visit.at(s)) {
                if (min+matrix.at(nxtNode).at(s) < dist.at(s)) {
                    dist.at(s) = min+matrix.at(nxtNode).at(s);
                }
            }
        }
    }

    for (int c=0; c<n; c++) {
        cout << "Distance of node " << c << " from " << src << " is " << 
            dist.at(c) << endl;
    }

    return 0;
}

