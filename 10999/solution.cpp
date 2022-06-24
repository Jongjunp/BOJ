#include <iostream>
using namespace std;
const int MAX = 1000000;
long long A[MAX+1];
long long tree[MAX*4 + 1];
long long lazy[MAX*4 + 1];

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
		tree[index] += lazy[index] * (end-start+1);
		if (start != end) {
			lazy[index * 2] += lazy[index];
			lazy[index * 2 + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
}

void updateTree(int index, int start, int end, long long val, int left, int right) {
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
    tree[index] = tree[index*2] + tree[index*2+1];
    return;
}

long long queryTree(int index, int start, int end, int left, int right) {
	propagateTree(index, start, end);
	if (right < start || end < left) return 0; // An exception
	if (left <= start && end <= right) {
		return tree[index];
	}
	int mid = (start + end) / 2;
	long long res1 = queryTree(index * 2, start, mid, left, right);
	long long res2 = queryTree(index * 2 + 1, mid + 1, end, left, right);
	return res1 + res2;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,M,K;
	cin >> N >> M >> K;
	for (int i = 1; i < N + 1; i++) {
		cin >> A[i];
	}
	initializeTree(1, 1, N);
	long long op, a, b, c;
	for (int i = 0; i < M+K; i++) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b >> c;
			updateTree(1, 1, N, c, a, b);
		}
		else {
			cin >> a >> b;
			cout << queryTree(1, 1, N, a, b) << "\n";
		}
	}
	return 0;
}