#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
int dp[MAX][2] = {0};
vector<int> tree[MAX];
bool visited[MAX] = {false};

void dfs(int node) {
    visited[node] = true;
    dp[node][1] = 1;
    vector<int>::iterator iter;
    for(iter=tree[node].begin(); iter!=tree[node].end(); iter++) {
        if (visited[*iter]) continue;
        dfs(*iter);
        dp[node][0] += dp[*iter][1];
        dp[node][1] += min(dp[*iter][0],dp[*iter][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,u,v;
    cin >> N;
    for (int i=0; i<N-1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[1][0],dp[1][1]) << endl;
}