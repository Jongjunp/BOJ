#include <iostream>
#include <algorithm>
using namespace std;
int in[8] = {0};
int answer[8];
int N,M;
void print_seq(int n, int idx) {
    if (n==M) {
        for (int i=0; i<M; i++) {
            printf("%d ", answer[i]);
        }
        printf("\n");
        return;
    }
    int prev_num = 0;
    for (int i=idx; i<N; i++) {
        if (in[i]!=prev_num) {
            answer[n] = in[i];
            prev_num = in[i];
            print_seq(n+1,i);
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> in[i];
    }
    sort(in,in+N);
    print_seq(0,0);
}