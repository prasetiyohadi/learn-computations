// Bellman-Ford Algorithm
#include <iostream>
#include <vector>
#include <map>

#define INF 999999999
using namespace std;

int main() {
    vector <vector<int>> matrix;
    map <int, char> Node;
    vector<int> dist;
    vector<int> pred;
    vector<int> route;
    int n, src, dest, nxtNode;

    n = 13;
    dest = 12;
    //n = 5;
    //dest = 4;
    src = 0;

    dist.clear();
    pred.clear();
    route.clear();
    for (int i=0; i<n; i++) {
        dist.push_back(0);
        pred.push_back(0);
    }

    Node[0] = 'A';
    Node[1] = 'B';
    Node[2] = 'C';
    Node[3] = 'D';
    Node[4] = 'E';
    Node[5] = 'F';
    Node[6] = 'G';
    Node[7] = 'H';
    Node[8] = 'I';
    Node[9] = 'J';
    Node[10] = 'K';
    Node[11] = 'L';
    Node[12] = 'M';

    /*
    matrix = {{0, 3, INF, 4, INF},
        {INF, 0, INF, 7, INF},
        {2, INF, 0, INF, 2},
        {INF, INF, 1, 0, 4},
        {INF, INF, INF, INF, 0}};
    */

    matrix = {{0, 10, 9, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF}, 
        {INF, 0, INF, INF, INF, 3, 4, 12, INF, INF, INF, INF, INF}, 
        {INF, INF, 0, 4, 8, INF, INF, INF, INF, INF, INF, INF, INF}, 
        {INF, INF, INF, 0, INF, INF, INF, INF, INF, 1, INF, INF, INF}, 
        {INF, INF, INF, INF, 0, INF, INF, INF, 3, INF, INF, INF, 6}, 
        {INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, 7, INF}, 
        {INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, 9, INF}, 
        {INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, 3, INF}, 
        {INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, 3, INF, INF}, 
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, 7}, 
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, 5}, 
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 4}, 
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}};

    dist = matrix.at(src);
    dist.at(src) = 0;
    pred.at(src) = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n; j++) {
            if (dist.at(j) < INF) {
                for (int k=0; k<n; k++) {
                    if (dist.at(j) + matrix.at(j).at(k) < dist.at(k)) {
                        dist.at(k) = dist.at(j) + matrix.at(j).at(k);
                        pred.at(k) = j;
                    }
                }
            }
        }
    }

    for (int j=0; j<n; j++)
        for (int k=0; k<n; k++)
            if (dist.at(j) + matrix.at(j).at(k) < dist.at(k)) {
                cout << "negative cycle detected! aborting..." << endl;
                return 1;
            }
       
    for (map<int, char>::iterator cc=Node.begin(); cc!=Node.end(); ++cc) {
        cout << "Shortest distance of node " << cc->second << " from " << 
            Node[0] << " is " << dist.at(cc->first) << " with predecessor "
            << Node[pred.at(cc->first)] << endl;
    }

    cout << "Shortest route from " << Node[src] << " to " << Node[dest] 
        << " is ";
    nxtNode = dest;
    route.push_back(nxtNode);
    while (nxtNode > src) {
        nxtNode = pred.at(nxtNode);
        route.push_back(nxtNode);
    }
    for (int i=route.size()-1; i>0; i--) cout << Node[route.at(i)] << " - ";
    cout << Node[dest] << endl;

    return 0;
}
