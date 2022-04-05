#include <iostream>
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main() {
    init();
    int N,M;
    int seq[200000] = {0};
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> seq[i];
    }
    int answer = 0;
    int left = 0;
    int right = 0;
    while (right!=N-1 || left!=N-1) {
        int sum = 0;
        for (int i=left; i<=right; i++) {
            sum += seq[i];
        }
        if (left == right) {
            if (sum == M) {
                answer += 1;
            }
            right += 1;
        }
        else if (sum > M) {
            left += 1;
        }
        else if (sum < M) {
            if (right+1==N) {
                break;
            }
            else {
                right += 1;
            }
        }
        else if (sum == M) {
            answer += 1;
            if (right+1==N) {
                break;
            }
            else {
                right += 1;
            }
        }
    }
    if (seq[N-1]==M) {
        answer += 1;
    }
    cout << answer << endl;
}