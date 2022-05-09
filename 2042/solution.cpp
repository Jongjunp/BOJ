#include <iostream>
using namespace std;
const int MAX = 1000000;
long long seq[MAX] = {0};
long long tree[4*MAX] = {0};
int N,M,K;
long long init(int start, int end, int node) {
    if (start==end) return tree[node] = seq[start];
    int mid = (start+end)/2;
    return tree[node] = init(start,mid,2*node)+init(mid+1,end,2*node+1);
}
long long sum(int start, int end, int node, int left, int right) {
    if (end<left || start>right) {
        return 0;
    }
    if (left<=start && end<=right) {
        return tree[node];
    }
    int mid = (start+end)/2;
    return sum(start,mid,2*node,left,right)+sum(mid+1,end,2*node+1,left,right);
}
void update(int start, int end, int node, int targ_idx, long long diff) {
    if (targ_idx<start || targ_idx>end) return;
    tree[node] = tree[node]+diff;
    if (start!=end) {
        int mid = (start+end)/2;
        update(start,mid,2*node,targ_idx,diff);
        update(mid+1,end,2*node+1,targ_idx,diff);
    }
    return;
}
int main() {
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        cin >> seq[i];
    }
    init(0,N-1,1);
    for (int i=0; i<M+K; i++) {
        long long op, a, b;
        cin >> op >> a >> b;
        if (op==1) {
            long long diff=b-seq[a-1];
            update(0,N-1,1,a-1,diff);
            seq[a-1]=b;
        }
        else {
            cout << sum(0,N-1,1,a-1,b-1) << endl;
        }
    }
}