#include <iostream>
#include <queue>
using namespace std;
const int MAX = 2000001;
int tree[4*MAX] = {0};

void update_tree(int node, int start, int end, int targ) {
    if (targ<start || targ>end) return;
    if (start==targ && end==targ) {
        tree[node] += 1;
        return;
    }
    int mid = (start+end)/2;
    update_tree(2*node, start, mid, targ);
    update_tree(2*node+1, mid+1, end, targ);
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}

int query_tree(int node, int start, int end, int order) {
    tree[node] -= 1;
    if (start==end) return start;
    int new_order = order-tree[2*node];
    int mid = (start+end)/2;
    if (new_order<=0) {
        return query_tree(2*node, start, mid, order);
    }
    else {
        return query_tree(2*node+1, mid+1, end, new_order);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,A,B;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A >> B;
        if (A==2) {
            cout << query_tree(1,1,MAX,B) << "\n";
        }
        else {
            update_tree(1,1,MAX,B);
        }
    }
}