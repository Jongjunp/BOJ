#include <iostream>
using namespace std;
const int DIVIDER = 1000000007;
int main(){
    unsigned long long nth;
    cin >> nth;
    unsigned long long dp[60][4] = {0};
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[0][3] = 0;
    for (int i=1; i<60; i++) {
        dp[i][0] = (((dp[i-1][0]*dp[i-1][0])%DIVIDER)+((dp[i-1][1]*dp[i-1][2])%DIVIDER))%DIVIDER;
        dp[i][1] = (((dp[i-1][0]*dp[i-1][1])%DIVIDER)+((dp[i-1][1]*dp[i-1][3])%DIVIDER))%DIVIDER;
        dp[i][2] = (((dp[i-1][0]*dp[i-1][2])%DIVIDER)+((dp[i-1][2]*dp[i-1][3])%DIVIDER))%DIVIDER;
        dp[i][3] = (((dp[i-1][1]*dp[i-1][2])%DIVIDER)+((dp[i-1][3]*dp[i-1][3])%DIVIDER))%DIVIDER;
    }
    int answer[4] = {1,0,1,0};
    unsigned long long bin_digit = 0;
    unsigned long long quotient = nth-1;
    while (quotient!=0) {
        if (quotient%2==1){
            int a = (((answer[0]*dp[bin_digit][0])%DIVIDER)+((answer[1]*dp[bin_digit][2])%DIVIDER))%DIVIDER;
            int b = (((answer[0]*dp[bin_digit][1])%DIVIDER)+((answer[1]*dp[bin_digit][3])%DIVIDER))%DIVIDER;
            int c = (((answer[2]*dp[bin_digit][0])%DIVIDER)+((answer[3]*dp[bin_digit][2])%DIVIDER))%DIVIDER;
            int d = (((answer[2]*dp[bin_digit][2])%DIVIDER)+((answer[3]*dp[bin_digit][3])%DIVIDER))%DIVIDER;
            answer[0] = a;
            answer[1] = b;
            answer[2] = c;
            answer[3] = d;
        }
        quotient = quotient/2;
        bin_digit += 1;
    }
    cout << answer[0] << endl;
}