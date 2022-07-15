#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int A[2*MAX] = {0};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    int ans = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        A[N+i] = A[i];
    }
    for (int i=1; i<2*N; i++) {
        A[i] += A[i-1];
    }
    for (int i=N; i <2*N; i++) {
		for (int j=i-N+1; j<N; j++) {
			ans = max(ans, min(A[i] - A[j], A[N+j] - A[i]));
		}
	}
    cout << ans << endl;
}