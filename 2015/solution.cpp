#include <iostream>
using namespace std;
const int MAX = 200000;
int integrate_sum[MAX] = {0};
int main() {
    int N,K,num;
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> num;
        if (i==0) {
            integrate_sum[i] = num;
        }
        else {
            integrate_sum[i] = integrate_sum[i-1]+num;
        }
    }
    for (int i=0; i<N; i++) {
        integrate_sum[] = 
    }
}