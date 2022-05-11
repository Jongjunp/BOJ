#include <iostream>
using namespace std;
const int MAX = 40;
int seq[MAX] = {0};
int tree[4*MAX] = {0};
void init(int start, int end, int node) {
    if (start==end) {
        tree[node] = seq[start];
        return;
    }
    int mid = (start+end)/2;
    init(start,mid,2*node);
    init(mid+1,end,2*node+1);
    tree[node] = tree[2*node]+tree[2*node+1];
}
int sum(int start, int end, int node, int left, int right) {
    if (left>end || start>right) return 0;
    if (left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start,mid,2*node,left,right)+sum(mid+1,end,2*node+1,left,right);
}
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int N,S;
    cin >> N >> S;
    for (int i=0; i<N; i++) {
        cin >> seq[i];
    }
    init(0,N-1,1);
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            if (sum(0,N-1,1,i,j)==S) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}