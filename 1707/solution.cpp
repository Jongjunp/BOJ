#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 20001;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int K,V,E,u,v;
    cin >> K;
    for (int t=0; t<K; t++) {
        vector<int> graph[MAX];
        int color[MAX] = {0};
        cin >> V >> E;
        for (int i=0; i<E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        bool isbipartite = true;
        for (int l=1; l<=V; l++) {
            if (color[l]==0) {
                q.push(l);
                color[l] = 1;
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    vector<int>::iterator iter;
                    for (iter=graph[node].begin(); iter!=graph[node].end(); iter++) {
                        if (color[*iter]==0) {
                            q.push(*iter);
                            if (color[node]==1) {
                                color[*iter] = 2;
                            }
                            else {
                                color[*iter] = 1;
                            }
                        }
                        else if (color[*iter]==color[node]) {
                            isbipartite = false;
                            break;
                        }
                    }
                    if (!isbipartite) {
                        break;
                    }
                }
                if (!isbipartite) {
                    break;
                }
            }
        }
        if (isbipartite) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}