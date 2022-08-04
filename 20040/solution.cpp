#include <iostream>
using namespace std;
const int MAX = 500001;
int parent[MAX] = {0};
int group_size[MAX]= {0};

int find_op(int x) {
    if (x==parent[x]) return x;
    parent[x] = find_op(parent[x]);
    return parent[x];
}

bool union_op(int x, int y) {
    int parent_x = find_op(x);
    int parent_y = find_op(y);
    if (parent_x==parent_y) return true;
    if (group_size[parent_x]>group_size[parent_y]) {
        parent[parent_y] = parent_x;
        group_size[parent_x] += group_size[parent_y];
        group_size[parent_y] = 0;
    }
    else {
        parent[parent_x] = parent_y;
        group_size[parent_y] += group_size[parent_x];
        group_size[parent_x] = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;
    int answer = 0;
    bool isanswer = false;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        parent[i] = i;
        group_size[i] = 1;
    }
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        if (union_op(a,b) && !isanswer) {
            answer=i;
            isanswer = true;
        }
    }
    cout << answer << endl;
}