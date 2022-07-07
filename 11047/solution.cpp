#include <iostream>
using namespace std;
const int MAX = 10;
int values[MAX] = {0};
int main() {
    int N,K,total_coin;
    total_coin = 0;
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> values[i];
    }
    for (int i=N-1; i>=0; i--) {
        total_coin += (K/values[i]);
        K = K%values[i];
    }
    cout << total_coin << endl;
}