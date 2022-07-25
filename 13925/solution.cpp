#include <iostream>
using namespace std;
const int MAX = 100001;
const int MOD = 1000000007;
long long A[MAX] = {0};
long long tree[4*MAX] = {0};
long long lazy[4*MAX][2] = {0};
long long initializeTree(int index, int start, int end) {
	if (start == end) return tree[index] = A[start];
	int mid = (start + end) / 2;
	return tree[index] = (initializeTree(index * 2, start, mid) + initializeTree(index * 2 + 1, mid + 1, end))%MOD;
}

void propagateTree(int index, int start, int end) {
	if (lazy[index][0] != 0 || lazy[index][1] != 1) {
		if (start != end) {
			lazy[index*2][0] = (lazy[index][1]*lazy[index*2][0]+lazy[index][0])%MOD;
			lazy[index*2+1][0] = (lazy[index][1]*lazy[index*2+1][0]+lazy[index][0])%MOD;
            lazy[index*2][1] = (lazy[index][1]*lazy[2*index][1])%MOD;
            lazy[index*2+1][1] = (lazy[index][1]*lazy[2*index+1][1])%MOD;
		}
        tree[index] = (lazy[index][1]*tree[index]+(end-start+1)*lazy[index][0])%MOD;
        lazy[index][1] = 1;
		lazy[index][0] = 0;
	}
}

void updateQuery(int index, int start, int end, int left, int right, long long addVal, long long mulVal) {
	propagateTree(index, start, end);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		lazy[index][0] = (lazy[index][0]+addVal)%MOD;
        lazy[index][1] = (lazy[index][1]*mulVal)%MOD;
		propagateTree(index, start, end);
		return;
	}
	int mid = (start + end) / 2;
	updateQuery(index * 2, start, mid, left, right, addVal, mulVal);
	updateQuery(index * 2 + 1, mid + 1, end, left, right, addVal, mulVal);
	tree[index] = (tree[index * 2] + tree[index * 2 + 1])%MOD;
}

long long printQuery(int index, int start, int end, int left, int right) {
	propagateTree(index, start, end);
    if (right < start || end < left) return 0;
	if (left <= start && end <= right) {
        return tree[index]%MOD;
	}
    int mid = (start+end)/2;
    return (printQuery(2*index,start,mid,left,right)+printQuery(2*index+1,mid+1,end,left,right))%MOD;
}

int main()
{
	int N;
	scanf("%d",&N);
    for (int i=1; i<=4*N; i++) {
        lazy[i][1] = 1;
    }
	for (int i=1; i<=N; i++) {
        scanf("%lld",&A[i]);
	}
	initializeTree(1, 1, N);
	int M;
	scanf("%d",&M);
	int op, x, y; 
    long long v;
	for (int i = 0; i < M; i++) {
		scanf("%d", &op);
		if (op != 4) {
			scanf("%d %d %lld", &x, &y, &v);
			if (op==1) {
                updateQuery(1,1,N,x,y,v,1);
            }
            if (op==2) {
                updateQuery(1,1,N,x,y,0,v);
            }
            if (op==3) {
                updateQuery(1,1,N,x,y,v,0);
            }
		}
		else {
			scanf("%d %d", &x, &y);
			printf("%lld\n",printQuery(1,1,N,x,y));
		}
	}
	return 0;
}