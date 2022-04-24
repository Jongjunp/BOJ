#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 10000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E;
    cin >> V >> E;
    int start;
    cin >> start;
    vector< pair<short,short> > graph[20001];
    int path[20001] = {0};
    for (int i=1; i<=V; i++) {
        if (i!=start) {
            path[i] = INF;
        }
    }
    for (int i=0; i<E; i++) {
        short v1,v2,w;
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
        vector< pair<short,short> >::iterator iter = graph[node].begin();
        for (; iter!=graph[node].end(); iter++) {
            short next_node = iter -> first;
            short weight = iter -> second;
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