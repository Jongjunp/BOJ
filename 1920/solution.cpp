#include <iostream>
using namespace std;
int main() {
    int N,M;
    int src_arr[100000] = {0};
    int targ_arr[100000] = {0};
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> src_arr[i];
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> targ_arr[i];
    }
    for (int i=0; i<M; i++) {
        int targ_num = targ_arr[i];
        int left = 0;
        int right = N-1;
        int mid = (left+right)/2;
        while (right>left) {
            if (src_arr[mid]<targ_num) {
                
            }
            else {

            }
            mid = (left+right)/2;
        }

    }
}