#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
const int MAX = 100000;
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main() {
    init();
    vector< pair<int,int> > graph[MAX];
    int coord[MAX][3] = {0};
    priority_queue< pair<int,int> > pq;
    bool visited[MAX] = {false};
    int vertex_num, dist;
    long long answer = 0;
    cin >> vertex_num;
    for (int i=0; i<vertex_num; i++) {
        cin >> coord[i][0] >> coord[i][1] >> coord[i][2];
        for (int j=0; j<i; j++) {
            dist = min({abs(coord[i][0]-coord[j][0]),abs(coord[i][1]-coord[j][1]),abs(coord[i][2]-coord[j][2])});
            graph[i].push_back(make_pair(j,dist));
            graph[j].push_back(make_pair(i,dist));
        }
    }
    vector< pair<int,int> >::iterator iter;
    for (iter=graph[0].begin(); iter!=graph[0].end(); iter++) {
        pq.push(make_pair(-(iter->second),iter->first));
    }
    visited[0] = true;
    while(!pq.empty()) {
        int weight = -pq.top().first;
        int node  = pq.top().second;
        pq.pop();
        if (visited[node]){
            continue;
        }
        answer += weight;
        visited[node] = true;
        vector< pair<int,int> >::iterator iter;
        for (iter=graph[node].begin(); iter!=graph[node].end(); iter++) {
            pq.push(make_pair(-(iter->second),iter->first));
        }
    }
    cout << answer << endl;
}