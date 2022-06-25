#include <iostream>
using namespace std;
const int MAX = 100000;
long long tree[MAX*4 + 1] = {0};
bool lazy[MAX*4 + 1] = {false};

void propagateTree(int index, int start, int end) {
	if (lazy[index]) {
		tree[index] = (end-start+1) - tree[index];
		if (start != end) {
			lazy[index * 2] = !lazy[index * 2];
			lazy[index * 2 + 1] = !lazy[index * 2 + 1];
		}
		lazy[index] = false;
	}
}

void updateTree(int index, int start, int end, int left, int right) {
	propagateTree(index, start, end);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		lazy[index] = true;
        propagateTree(index, start, end);
        return;
	}
	int mid = (start + end) / 2;
	updateTree(index * 2, start, mid, left, right);
	updateTree(index * 2 + 1, mid + 1, end, left, right);
    tree[index] = tree[index*2] + tree[index*2+1];
    return;
}

long long queryTree(int index, int start, int end, int left, int right) {
	propagateTree(index, start, end);
	if (right < start || end < left) return 0;
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
	int N,M;
	cin >> N >> M;
	long long op, a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> op >> a >> b;
		if (op == 0) {
			updateTree(1, 1, N, a, b);
		}
		else {
			cout << queryTree(1, 1, N, a, b) << "\n";
		}
	}
	return 0;
}