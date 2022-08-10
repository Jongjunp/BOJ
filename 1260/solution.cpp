#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
vector<int> graph[MAX];
bool visited_dfs[MAX] = {false};
bool visited_bfs[MAX] = {false};

void dfs(int cur) {
    cout << cur << " ";
    vector<int>::iterator iter;
    for (iter=graph[cur].begin(); iter!=graph[cur].end(); iter++) {
        if (!visited_dfs[*iter]){
            visited_dfs[*iter] = true;
            dfs(*iter);
        }
    }
    return;
}

int main() {
    int N,M,V,u,v;
    cin >> N >> M >> V;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i=1; i<=N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    visited_dfs[V] = true;
    dfs(V);
    cout << "\n";
    queue<int> q;
    q.push(V);
    visited_bfs[V] = true;
    while(!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        vector<int>::iterator iter;
        for (iter=graph[node].begin(); iter!=graph[node].end(); iter++) {
            if (!visited_bfs[*iter]){
                q.push(*iter);
                visited_bfs[*iter] = true;
            }
        }
    }
    cout << "\n";
}