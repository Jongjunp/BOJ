#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
int dp[MAX][2] = {0};
vector<int> tree[MAX];
int main() {
    int N,u,v;
    cin >> N;
    for (int i=1; i<=N; i++) {
        dp[i][1] = 1;
    }
    for (int i=0; i<N-1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i=1; i<=N; i++) {
        vector<int>::iterator iter;
        for (iter=tree[i].begin(); iter!=tree[i].end(); iter++) {
            dp[i][0] += dp[*iter][1];
            dp[i][1] += min(dp[*iter][0], dp[*iter][1]);
        }
    }
    // no matter what state the node is
    cout << min(dp[1][0],dp[1][1]) << endl;
}