#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
int seq[MAX] = {0};
int tree[4*MAX] = {0};
int N,M;
int init(int start, int end, int node) {
    if (start==end) {
        tree[node] = start;
        return;
    }
    int mid = (start+end)/2;
    init(start,mid,2*node);
    init(mid+1,end,2*node+1);
    if (seq[tree[2*node]]<seq[tree[2*node+1]]) {
        tree[node] = tree[2*node];
    }
    else{
        tree[node] = tree[2*node+1];
    }
}
int query(int start, int end, int node, int left, int right) {
    if (end<left || start>right) {
        return -1;
    }
    if (left<=start && end<=right) {
        return tree[node];
    }
    int mid = (start+end)/2;
    int res1 = query(start,mid,2*node,left,right);
    int res2 = query(mid+1,end,2*node+1,left,right);
    if (res1 == -1) {
        return res2;
    }
    if (res2 == -1) {
        return res1;
    }
    else {
        if (seq[res1]<seq[res2]) {
            return res1;
        }
        else {
            return res2;
        }
    }
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
    for (int i=0; i<M; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op==1) {
            seq[a-1] = b;
            init(0,N-1,1);
        }
        else {
            cout << query(0,N-1,1,a-1,b-1)+1 << endl;
        }
    }
}