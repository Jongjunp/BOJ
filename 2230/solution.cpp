#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int A[MAX] = {0};
int main() {
    int N,M;
    int answer = 2000000001;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A,A+N);
    int left = 0;
    int right = 1;
    while (right<N) {
        if (A[right]-A[left]<M) {
            right += 1;
            continue;
        }
        if (A[right]-A[left]==M) {
            answer = A[right]-A[left];
            break;
        }
        if (A[right]-A[left]<answer) {
            answer = A[right]-A[left];
        }
        left += 1;
    }
    cout << answer << endl;
}