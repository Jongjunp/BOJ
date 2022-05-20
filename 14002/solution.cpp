#include <iostream>
#include <vector>
using namespace std;
int seq[1000] = {0};
int input[1000] = {0};
int seqidxes[1000] = {0};
vector<int> answer[1000];
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
            answer[0].push_back(num);
            maxfill++;
            seqidx++;
            continue;
        }
        if (num > seq[seqidx-1]) {
            seq[seqidx] = num;
            seqidxes[seqidx] = i;
            answer[i].clear();
            answer[i].assign(answer[maxidx].begin(),answer[maxidx].end());
            answer[i].push_back(num);
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
        answer[i].clear();
        if (mid<1) {
            answer[i].push_back(num);
        }
        else {
            answer[i].assign(answer[seqidxes[mid-1]].begin(),answer[seqidxes[mid-1]].end());
            answer[i].push_back(num);
        }
        seqidxes[mid] = i;
        if (mid==seqidx-1) {
            maxidx = i;
        }
    }
    cout << maxfill << endl;
    vector<int>::iterator iter = answer[maxidx].begin();
    for (; iter!=answer[maxidx].end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}