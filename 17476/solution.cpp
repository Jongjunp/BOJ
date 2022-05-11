#include <iostream>
using namespace std;
const int MAX = 100001;
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
	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

void propagateTree(int index, int start, int end) {
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (start != end) {
			lazy[index*2] += lazy[index];
			lazy[index*2+1] += lazy[index];
		}
		lazy[index] = 0;
	}
}

void updateTree(int index, int start, int end, int val, int left, int right) {
	propagateTree(index, start, end);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		lazy[index] += val;
		propagateTree(index, start, end);
		return;
	}
	int mid = (start + end) / 2;
	updateTree(index * 2, start, mid, val, left, right);
	updateTree(index * 2 + 1, mid + 1, end, val, left, right);
	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

long long queryTree(int index, int start, int end, int targ) {
	propagateTree(index, start, end);
    if (start==end) return tree[index];
    int mid = (start+end)/2;
    if (targ<=mid) return queryTree(2*index,start,mid,targ);
    else return queryTree(2*index+1,mid+1,end,targ);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> A[i];
	}
	initializeTree(1, 1, N);
	int M;
	cin >> M;
	int op, a, b, c, x;
	for (int i = 0; i < M; i++) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b >> c;
			updateTree(1, 1, N, c, a, b);
		}
		else {
			cin >> x;
			cout << queryTree(1, 1, N, x) << "\n";
		}
	}
	return 0;
}