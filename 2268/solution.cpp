#include <iostream>
using namespace std;
const int MAX = 1000001;
long long seq[MAX] = {0};
long long tree[4*MAX] = {0};
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
	int N,M;
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        long long op, a, b;
        scanf("%lld %lld %lld", &op, &a, &b);
        if (op==1) {
            long long diff=b-seq[a];
            seq[a]=b;
            update(1,N,1,a,diff);
        }
        else {
            if (a>b) {
                printf("%lld\n", sum(1,N,1,b,a));
            }
            else {
                printf("%lld\n", sum(1,N,1,a,b));
            }
        }
    }
}