#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 51;
int dp[MAX] = {0};
vector<int> tree[MAX];
bool visited[MAX] = {false};

void dfs(int node) {
    visited[node] = true;
    dp[node] = 0;
    vector<int>::iterator iter;
    vector<int> find_order;
    int cnt = 1;
    for(iter=tree[node].begin(); iter!=tree[node].end(); iter++) {
        if (visited[*iter]) continue;
        dfs(*iter);
        find_order.push_back(dp[*iter]);
    }
    if (find_order.empty()) {
        return;
    }
    sort(find_order.begin(),find_order.end(),greater<int>());
    for (iter=find_order.begin(); iter!=find_order.end(); iter++) {
        if (*iter+cnt>dp[node]) {
            dp[node] = *iter+cnt;
        }
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,u;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> u;
        if (u==-1) {
            continue;
        }
        tree[i].push_back(u);
        tree[u].push_back(i);
    }
    dfs(0);
    cout << dp[0] << endl;
}