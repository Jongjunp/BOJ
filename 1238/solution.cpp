#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;
int V,E,X;
int max_time = 0;
int graph[1001][1001] = {0};
int path[1001] = {0};
int post_time[1001] = {0};
void dijkstra(int start, int goal) {
    path[start] = 0;
    for (int i=1; i<=V; i++) {
        if (i!=start) {
            path[i] = INF;
        }
    }
    priority_queue< pair<int,int> > pq;
    pair<int,int> init = make_pair(-path[start],start);
    pq.push(init);
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (path[node]<cost) {
            continue;
        }
        if (node==goal) {
            break;
        }
        for (int i=1; i<=V; i++) {
            if (path[i]>cost+graph[node][i] && i!=node && graph[node][i]!=0) {
                path[i] = cost+graph[node][i];
                pq.push(make_pair(-path[i],i));
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E >> X;
    for (int i=0; i<E; i++) {
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = w;
    }
    dijkstra(X,-1);
    for (int i=1; i<=V; i++) {
        post_time[i] = path[i];
    }
    for (int k=1; k<=V; k++) {
        dijkstra(k,X);
        int cost = path[X]+post_time[k];
        if (max_time<cost) {
            max_time = cost;
        }
    }
    cout << max_time << endl;
}