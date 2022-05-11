#include <iostream>
using namespace std;
const int MAX = 500001;
int N,M;
int seq[MAX] = {0};
int tree[4*MAX] = {0};
int lazy[4*MAX] = {0};
void init(int start, int end, int node) {
    if (start==end) {
        tree[node] = seq[start];
        return;
    }
    int mid = (start+end)/2;
    init(start,mid,2*node);
    init(mid+1,end,2*node+1);
    tree[node] = tree[2*node] ^ tree[2*node+1];
    return;
}
void propagate(int start, int end, int node) {
    if (lazy[node]!=0) {
        if ((end-start+1)%2==1) tree[node] ^= lazy[node];
        if (start!=end) {
            lazy[2*node] ^= lazy[node];
            lazy[2*node+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int start, int end, int node, int left, int right, int val) {
    propagate(start,end,node);
    if (right<start || left>end) return;
    if (left<=start && end<=right) {
        lazy[node] ^= val;
        propagate(start,end,node);
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,2*node,left,right,val);
    update(mid+1,end,2*node+1,left,right,val);
    tree[node] = tree[2*node] ^ tree[2*node+1];
}
int XOR(int start, int end, int node, int left, int right) {
    propagate(start,end,node);
    if (right<start || left>end) return 0;
    if (left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    int res1 = XOR(start,mid,2*node,left,right);
    int res2 = XOR(mid+1,end,2*node+1,left,right);
    return  res1^res2 ;
}
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> seq[i];
    }
    init(0,N-1,1);
    cin >> M;
    int op,i,j,k;
    for (int l=0; l<M; l++) {
        cin >> op;
        if (op==1) {
            cin >> i >> j >> k;
            update(0,N-1,1,i,j,k);
        }
        else {
            cin >> i >> j;
            cout << XOR(0,N-1,1,i,j) << endl;
        }
    }
    return 0;
}