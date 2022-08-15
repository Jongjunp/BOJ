#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;

int dp[MAX] = {0};

int main() {
    int n,num;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num;
        if (i==0) {
            dp[i] = num;
        }
        else {
            dp[i] = dp[i-1]
        }
    }
}