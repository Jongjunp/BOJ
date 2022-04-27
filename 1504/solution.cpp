#include <iostream>
#include <queue>
#include <utility>
using namespace std;
const int INF = 987654321;
int graph[801][801] = {0};
int N,E,v1,v2,u,v,c,answer;
int dijkstra(int start, int dest) {
    int dist[801] = {0};
    for (int i=1; i<=N; i++) {
        if(i!=start) {
            dist[i] = INF;
        }
    }
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(-dist[start],start));
    while(!pq.empty()) {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[node]<cost) {
            continue;
        }
        for (int i=1; i<=N; i++) {
            if (graph[node][i]!=0 && dist[i]>cost+graph[node][i]) {
                dist[i] = cost+graph[node][i];
                pq.push(make_pair(-dist[i],i));
            }
        }
    }
    return dist[dest];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> E;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> c;
        graph[u][v] = c;
        graph[v][u] = c;
    }
    cin >> v1 >> v2;
    int input_list1[4] = {1,v1,v2,N};
    int input_list2[4] = {1,v2,v1,N};
    int sum1 = 0;
    int sum2 = 0;
    for (int i=0; i<3; i++) {
        int temp_res = dijkstra(input_list1[i],input_list1[i+1]);
        if (temp_res==INF) {
            sum1 = -1;
            break;
        }
        else {
            sum1 += temp_res;
        }
    }
    for (int i=0; i<3; i++) {
        int temp_res = dijkstra(input_list2[i],input_list2[i+1]);
        if (temp_res==INF) {
            sum2 = -1;
            break;
        }
        else {
            sum2 += temp_res;
        }
    }
    if (sum1 < sum2) {
        cout << sum1 << endl;
    }
    else {
        cout << sum2 << endl;
    }
}