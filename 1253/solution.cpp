#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 2001;
int seq[MAX] = {0};

int main() {
    int N;
    cin >> N;
    int answer = 0;
    for (int i=0; i<N; i++) {
        cin >> seq[i];
    }
    sort(seq,seq+N);
    for (int i=0; i<N; i++) {
        int left = 0;
        int right = N-1;
        int targ = seq[i];
        while(left<right) {
            if (seq[left]+seq[right]==targ) {
                if (left==i) {
                    left++;
                }
                else if (right==i) {
                    right--;
                }
                else {
                    answer++;
                    break;
                }
            }
            else if (seq[left]+seq[right]<targ) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    cout << answer << endl;
}