#include <bits/stdc++.h>
using namespace std;

int A[500001];
int tree[500000 * 4 + 1];
int lazy[500000 * 4 + 1];

void initializeTree(int index, int start, int end) {
	if (start == end) {
		tree[index] = A[start];
		return;
	}

	int mid = (start + end) / 2;
	initializeTree(index * 2, start, mid);
	initializeTree(index * 2 + 1, mid + 1, end);

	tree[index] = tree[index * 2] ^ tree[index * 2 + 1];
}

void propagateTree(int index, int start, int end) {
	if (lazy[index] != 0) {
		if ((end - start + 1) % 2 == 1) {
			tree[index] ^= lazy[index];
		}

		if (start != end) {
			lazy[index * 2] ^= lazy[index];
			lazy[index * 2 + 1] ^= lazy[index];
		}

		lazy[index] = 0;
	}
}

void updateTree(int index, int start, int end, int val, int left, int right) {
	propagateTree(index, start, end);

	if (right < start || end < left) return;

	if (left <= start && end <= right) {
		lazy[index] ^= val;
		propagateTree(index, start, end);

		return;
	}

	int mid = (start + end) / 2;
	updateTree(index * 2, start, mid, val, left, right);
	updateTree(index * 2 + 1, mid + 1, end, val, left, right);

	tree[index] = tree[index * 2] ^ tree[index * 2 + 1];
}

int queryTree(int index, int start, int end, int left, int right) {
	propagateTree(index, start, end);

	if (right < start || end < left) return 0; // An exception

	if (left <= start && end <= right) {
		return tree[index];
	}

	int mid = (start + end) / 2;
	int res1 = queryTree(index * 2, start, mid, left, right);
	int res2 = queryTree(index * 2 + 1, mid + 1, end, left, right);

	return res1 ^ res2;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int i;
	for (i = 1; i < N + 1; i++) {
		cin >> A[i];
	}

	initializeTree(1, 1, N);

	int M;
	cin >> M;
	int op, a, b, c;
	for (i = 0; i < M; i++) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b >> c;
			updateTree(1, 1, N, c, a + 1, b + 1);
		}
		else {
			cin >> a >> b;
			cout << queryTree(1, 1, N, a + 1, b + 1) << "\n";
		}
	}

	return 0;
}