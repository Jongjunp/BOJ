#include <iostream>
using namespace std;
const int MAX = 300000;
int main() {
    int N,K;
    int jewel[MAX][2] = {0};
    int bag[MAX] = {0};
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> jewel[i][0] >> jewel[i][1];
    }
    for (int j=0; j<K; j++) {
        cin >> bag[j];
    }
    
    
}