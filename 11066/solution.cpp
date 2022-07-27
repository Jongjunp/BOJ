#include <iostream>
#include <vector>
using namespace std;
const int MAX = 501;

int arr[MAX] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;
    
    for(int t=0; t<testCase; t++) {
        int dp[MAX][MAX] = {0};
        int num;
        cin >> num;
        for(int i=0; i<num; i++) {
            cin >> arr[i];
        }
        for (int i=1; i<num; i++) {
            for (int j=i-1; j>=0; j--) {
                if (i-j==1) {
                    dp[i][j] = arr[i] + arr[j];
                    continue;
                }
                else {
                    int min_val = 0;
                    for (int k=i; k>=j; k--) {
                        min_val += arr[k];
                    }
                    dp[i][j] = 1000000007;
                    for (int k=i; k>j; k--) {
                        if (dp[i][j]>min_val+dp[i][k]+dp[k-1][j]) {
                            dp[i][j] = min_val+dp[i][k]+dp[k-1][j];
                        }
                    }
                }
            }
        }
        cout << dp[num-1][0] << endl;
    }
}
