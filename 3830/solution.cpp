#include <iostream>
using namespace std;
const int MAX = 100001;
int parent[MAX] = {0};
int diff[MAX] = {0};

int find_op(int x) {
    if (x==parent[x]) return x;
    int parent_x = find_op(parent[x]);
    diff[x] += diff[parent[x]];
    return parent[x] = parent_x;
}

void union_op(int x, int y, int w) {
    int parent_x = find_op(x);
    int parent_y = find_op(y);
    diff[x]
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M,a,b,w;
    char op;
    while (true) {
        cin >> N >> M;
        for (int i=1; i<=N; i++) {
            parent[i] = i;
            diff[i] = 0;
        }
        if (N==0 && M==0) break;
        for (int i=0; i<M; i++) {
            cin >> op;
            if (op=='!') {
                cin >> a >> b >> w;
                union_op(a,b,w);
            }
            else {
                cin >> a >> b;
                int parent_a = find_op(a);
                int parent_b = find_op(b);
                if (parent_a==parent_b) {
                    cout << diff[b]-diff[a] << "\n";
                }
                else {
                    cout << "UNKNOWN\n";
                }
            }
            for (int k=1; k<=N; k++) {
                cout << diff[k] << " ";
            }
            cout << endl;
        }
    }
}