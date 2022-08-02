#include <iostream>
using namespace std;
const int MAX = 201;
int parent[MAX] = {0};
int rabel[MAX] = {0};

int find_op(int x) {
    if (x==parent[x]) return x;
    parent[x] = find_op(parent[x]);
    return parent[x];
}

void union_op(int x, int y) {
    int parent_x = find_op(x);
    int parent_y = find_op(y);
    if (parent_x==parent_y) return;
    if (rabel[parent_x]>rabel[parent_y]) {
        parent[parent_y] = parent_x;
        rabel[parent_x] += rabel[parent_y];
        rabel[parent_y] = 0;
    }
    else {
        parent[parent_x] = parent_y;
        rabel[parent_y] += rabel[parent_x];
        rabel[parent_x] = 0;
    }
}

int main() {
    int N,M,connected,node,travel_parent;
    bool answer;
    travel_parent = 0;
    cin >> N;
    cin >> M;
    for (int i=1; i<=N; i++) {
        parent[i] = i;
        rabel[i] = 1;
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> connected;
            if (connected) {
                union_op(i,j);
            }
        }
    }
    for (int i=0; i<M; i++) {
        cin >> node;
        if (travel_parent==0) {
            travel_parent = find_op(node);
            answer = true;
        }
        else {
            if (travel_parent!=find_op(node)) {
                answer = false;
                break;
            }
        }
    }
    if (answer) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}