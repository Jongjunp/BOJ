#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX = 100001;
int A[MAX] = {0};
int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    int left = 0;
    int right = N-1;
    int min_sum = A[left]+A[right];
    int min_sum_abs = abs(min_sum);
    while (right>left) {
        int sum = A[left]+A[right];
        if (abs(sum)<min_sum_abs) {
            min_sum = sum;
            min_sum_abs = abs(sum);
        }
        if (sum<0) {
            left += 1;
        }
        else if (sum>0){
            right -= 1;
        }
        else {
            break;
        }
    }
    cout << min_sum << endl;
}