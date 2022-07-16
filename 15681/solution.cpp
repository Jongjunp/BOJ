#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100001;
vector<int> tree[MAX];
int dp[MAX] = {0};
bool visited[MAX] = {false};

void dfs(int node) {
    dp[node] = 1;
    visited[node] = true;
    vector<int>::iterator iter;
    for (iter=tree[node].begin(); iter!=tree[node].end(); iter++) {
        if (visited[*iter]) continue;
        dfs(*iter);
        dp[node] += dp[*iter];
    }
}

int main() {
    int N,R,Q,u,v,q;
    scanf("%d %d %d", &N, &R, &Q);
    for (int i=0; i<N-1; i++) {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(R);
    for (int i=0; i<Q; i++) {
        scanf("%d", &q);
        printf("%d\n", dp[q]);
    }
}