#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 50;
vector<int> tree[MAX];
queue<int> q;
int dp[MAX] = {0};

bool compare(int a, int b) {
    return tree[a].size() > tree[b].size();
}

int main() {
    int n,v;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d",&v);
        if (v==-1) {
            continue;
        }
        tree[v].push_back(i);
    }
    q.push(0);
    int min_time = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        vector<int>::iterator iter;
        int cnt = 1;
        sort(tree[node].begin(),tree[node].end(), compare);
        for (iter=tree[node].begin(); iter!=tree[node].end(); iter++) {
            if (*iter<node) continue;
            q.push(*iter);
            dp[*iter] = dp[node]+cnt;
            cnt += 1;
        }
    }
    for (int i=0; i<n; i++) {
        if (tree[i].empty() && dp[i]>min_time) {
            min_time = dp[i];
        }
    }
    printf("%d\n",min_time);
}