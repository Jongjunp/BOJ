#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100001;
vector<int> tree[MAX];
int dp[MAX] = {0};

void dfs(int node) {
    vector<int>::iterator iter;
    for (iter=tree[node].begin(); iter!=tree[node].end(); iter++) {
        if (*iter<node) continue;
        dp[*iter] += dp[node];
        dfs(*iter);
    }
}

int main() {
    int n,m,v,l,w;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d",&v);
        if (v==-1) {
            continue;
        }
        tree[i].push_back(v);
        tree[v].push_back(i);
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d", &l, &w);
        dp[l] += w;
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");
}