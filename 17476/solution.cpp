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

void updateAdditionTree(int index, int start, int end, int val, int left, int right) {
	propagateTree(index, start, end);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		lazy[index] += val;
		propagateTree(index, start, end);
		return;
	}
	int mid = (start + end) / 2;
	updateAdditionTree(index * 2, start, mid, val, left, right);
	updateAddtionTree(index * 2 + 1, mid + 1, end, val, left, right);
	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}
void updateSqrtTree() {
    
}
long long queryTree(int index, int start, int end, int left, int right) {
	propagateTree(index, start, end);
    if (right<start || end<left) return 0;
    if (left<=start && end<=right) return tree[index];
    int mid = (start+end)/2;
    return queryTree(2*index,start,mid,left,right)+queryTree(2*index+1,mid+1,end,left,right);
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
	int op, L, R, X;
	for (int i = 0; i < M; i++) {
		cin >> op;
		if (op == 1) {
			cin >> L >> R >> X;
			updateAdditionTree(1, 1, N, X, L, R);
		}
        else if (op == 2) {

        }
		else {
			cin >> x;
			cout << queryTree(1, 1, N, L, R) << "\n";
		}
	}
	return 0;
}