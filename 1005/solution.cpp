#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 10000000;
int T,V,E;
int graph[1001][1001] = {0};
int path[1001] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int n=0; n<T; n++) {
        cin >> V >> E;
        int start;
        cin >> start;
        for (int i=1; i<=V; i++) {
            if (i!=start) {
                path[i] = INF;
            }
        }
        for (int i=0; i<E; i++) {
            int v1,v2,w;
            cin >> v1 >> v2 >> w;
            graph[v1].push_back(make_pair(v2,w));
        }
        priority_queue< pair<int,int> > pq;
        pair<int,int> init = make_pair(-path[start],start);
        pq.push(init);
        while (!pq.empty()) {
            int cost = -pq.top().first;
            int node = pq.top().second;
            pq.pop();
            vector< pair<int,int> >::iterator iter = graph[node].begin();
            for (; iter!=graph[node].end(); iter++) {
                int next_node = iter -> first;
                int weight = iter -> second;
                if (path[next_node]>cost+weight) {
                    path[next_node] = cost+weight;
                    pq.push(make_pair(-path[next_node],next_node));
                }
            }
        }
        for (int i=1; i<=V; i++) {
            if (path[i]==INF) {
                cout << "INF" << endl;
            }
            else {
                cout << path[i] << endl;
            }
        }
    }
}