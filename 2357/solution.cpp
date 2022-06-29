#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int MAX_VAL = 1000000001;
const int MIN_VAL = 0;
int A[MAX] = {0};
int maxtree[4*MAX] = {0};
int mintree[4*MAX] = {0};

void initialize(int index, int start, int end) {
    if (start==end) {
        maxtree[index] = A[start];
        mintree[index] = A[start];
        return;
    }
    int mid = (start+end)/2;
    initialize(2*index, start, mid);
    initialize(2*index+1, mid+1, end);
    maxtree[index] = max(maxtree[2*index],maxtree[2*index+1]);
    mintree[index] = min(mintree[2*index],mintree[2*index+1]);
    return;
}

int maxquery(int index, int start, int end, int left, int right) {
    if (start>right || left>end) return MIN_VAL;
    if (left<=start && end<=right) return maxtree[index];
    int mid = (start+end)/2;
    int max1 = maxquery(2*index, start, mid, left, right);
    int max2 = maxquery(2*index+1, mid+1, end, left, right);
    return max(max1,max2);
}

int minquery(int index, int start, int end, int left, int right) {
    if (start>right || left>end) return MAX_VAL;
    if (left<=start && end<=right) return mintree[index];
    int mid = (start+end)/2;
    int min1 = minquery(2*index, start, mid, left, right);
    int min2 = minquery(2*index+1, mid+1, end, left, right);
    return min(min1,min2);
}

int main() {
    int N,M,a,b;
    scanf("%d %d",&N, &M);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
    }
    initialize(1,1,N);
    for (int i=0; i<M; i++) {
        scanf("%d %d",&a, &b);
        printf("%d %d\n",minquery(1,1,N,a,b),maxquery(1,1,N,a,b));
    }
}