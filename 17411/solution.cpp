#include <iostream>
using namespace std;
const int MAX = 1000001;
int seq[MAX] = {0};
int input[MAX] = {0};
int seqidxes[MAX] = {0};
int answer[MAX] = {0};
int N, num, start, final, mid, maxfill, maxidx, seqidx;
int main() {
    cin >> N;
    maxfill = 0;
    maxidx = 0;
    seqidx = 0;
    for (int i=0; i<N; i++) {
        cin >> input[i];
    }
    for (int i=0; i<N; i++) {
        num = input[i];
        if (i==0) {
            seq[0] = num;
            seqidxes[0] = i;
            maxfill++;
            seqidx++;
            continue;
        }
        if (num > seq[seqidx-1]) {
            seq[seqidx] = num;
            seqidxes[i] = seqidx;
            maxfill++;
            maxidx = i;
            seqidx++;
            continue;
        }
        start = 0;
        final = seqidx-1;
        mid = (start+final)/2;
        while (final>start) {
            if (seq[mid] < num) {
                start = mid+1;
            }
            else {
                final = mid;
            }
            mid = (start+final)/2;
        }
        seq[mid] = num;
        seqidxes[i] = mid;
        if (mid==seqidx-1) {
            maxidx = i;
        }
    }
    cout << maxfill << endl;
    int last = maxfill-1;
    for (int i=N-1; i>=0; i--) {
        if (last < 0) {
            break;
        }
        if (seqidxes[i] == last) {
            answer[last] = input[i];
            last--;
        }
    }
    for (int i=0; i<maxfill; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}