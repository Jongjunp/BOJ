#include <iostream>
using namespace std;
const int MAX = 1000001;
int n,m;
int parent[MAX] = {0};
int num_childs[MAX] = {0};

int find_op(int x) {
    if (x==parent[x]) return x;
    parent[x] = find_op(parent[x]);
    return parent[x];
}

void union_op(int a, int b) {
    int parent_a = find_op(a);
    int parent_b = find_op(b);
    if (parent_a==parent_b) return;
    if (num_childs[parent_a]>num_childs[parent_b]) {
        parent[parent_b] = parent_a;
        num_childs[parent_a] += num_childs[parent_b];
        num_childs[parent_b] = 0;
    }
    else {
        parent[parent_a] = parent_b;
        num_childs[parent_b] += num_childs[parent_a];
        num_childs[parent_a] = 0;
    }
}

bool check_op(int a, int b) {
    int parent_a = find_op(a);
    int parent_b = find_op(b);
    if (parent_a==parent_b) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int op, a, b;
    for (int i=0; i<=n; i++) {
        parent[i] = i;
        num_childs[i] = 0;
    }
    for (int i=0; i<m; i++) {
        cin >> op >> a >> b;
        if (op==0) {
            union_op(a,b);
        }
        else {
            if (check_op(a,b)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}