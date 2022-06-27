#include <iostream>
using namespace std;
const int MAX = 1000001;
const int DIV = 1000000007;
int A[MAX] = {0};
long long tree[4*MAX] = {0};
long long lazy[4*MAX] = {0};
void initializeTree(int index, int start, int end) {
	if (start == end) {
		tree[index] = A[start];
		return;
	}
	int mid = (start + end) / 2;
	initializeTree(index * 2, start, mid);
	initializeTree(index * 2 + 1, mid + 1, end);
	tree[index] = (tree[index*2] * tree[index*2+1])%DIV;
}

long long updateTree(int index, int start, int end, long long val, int targ_idx) {
	if (targ_idx < start || end < targ_idx) return tree[index];
    if (start == end) return tree[index] = val;
	int mid = (start + end) / 2;
    return tree[index] = (updateTree(index * 2, start, mid, val, targ_idx)*updateTree(index * 2 + 1, mid + 1, end, val, targ_idx))%DIV;
}

long long queryTree(int index, int start, int end, int left, int right) {
    if (end<left || start>right) return 1;
    if (left<=start && end<=right) {
        return tree[index]%DIV;
    }
    int mid = (start+end)/2;
    return (queryTree(2*index,start,mid,left,right)*queryTree(2*index+1,mid+1,end,left,right))%DIV;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,M,K;
	cin >> N >> M >> K;
	for (int i=1; i<=N; i++) {
		cin >> A[i];
	}
	initializeTree(1, 1, N);
	int a, b, c;
	for (int i = 0; i < M+K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
            updateTree(1, 1, N, c, b);
            A[b] = c;
		}
		else {
			cout << queryTree(1, 1, N, b, c) << "\n";
		}
	}
	return 0;
}