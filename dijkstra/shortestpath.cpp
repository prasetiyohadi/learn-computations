#include <iostream>
#include <vector>
#include <map>

#define INF 999999999
using namespace std;

int main() {
    vector <vector<int>> matrix;
    map <int, char> Node;
    vector<int> dist;
    vector<bool> visit;
    int n, src, dest, nxtNode, min;

    n = 13;
    src = 0;
    dest = 12;

    dist.clear();
    visit.clear();
    for (int i=0; i<n; i++) {
        dist.push_back(0);
        visit.push_back(false);
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
    visit.at(src) = true;

    for (int i=0; i<n; i++) {
        min = INF;
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

    for (map<int, char>::iterator cc=Node.begin(); cc!=Node.end(); ++cc) {
        cout << "Shortest distance of node " << cc->second << " from " << 
            Node[0] << " is " << dist.at(cc->first) << endl;
    }

    return 0;
}
