#include <iostream>
using namespace std;
const int MAX = 1001;
bool dp[MAX] = {false};

int main() {
    int N;
    scanf("%d", &N);
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    for (int i=4; i<=N; i++) {
        if (dp[i-1] || dp[i-3]) dp[i] = false;
        else dp[i] = true;
    }
    if (dp[N]) {
        printf("SK\n");
    }
    else {
        printf("CY\n");
    }
}