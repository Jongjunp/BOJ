#include <iostream>
#include <algorithm>
const int MAX = 20001;
using namespace std;
int center[MAX] = {0};
int dist[MAX] = {0};

int find_op(int x) {
    if (x==center[x]) return x;
    int center_x = find_op(center[x]);
    dist[x] += dist[center[x]];
    return center[x] = center_x;
}

void union_op(int x, int y) {
    dist[x] = abs(x-y)%1000;
    center[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N, i, j;
    char op;
    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> N;
        for (int u=1; u<=N; u++) {
            center[u] = u;
            dist[u] = 0;
        }
        while (true) {
            cin >> op;
            if (op=='O') {
                break;
            }
            else if (op=='I') {
                cin >> i >> j;
                union_op(i,j);
            }
            else {
                cin >> i;
                int temp = find_op(i);
                cout << dist[i] << "\n";
            }
        }
    }
}