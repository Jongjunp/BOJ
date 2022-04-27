#include <iostream>
#include <queue>
using namespace std;
int seq[1000] = {0};
vector<int> answer[1000];
int N, num, start, final, mid;
int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> num;
        start = 0;
        final = 
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
        if (seq[mid]<num) {
            seq[mid+1] = num;
        }
        else {
            seq[mid] = num;
        }
        answer[i].push();

    }
    cout << maxfill << endl;
    int p = 0;
    while(answer[p]!=0) {
        cout << answer[p] << " ";
        p++;
    }
    cout << endl;
}