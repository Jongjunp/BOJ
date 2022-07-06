#include <iostream>
#include <vector>
#include <queue>
#include <utility>
const int MAX = 200001;
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
//prim algorithm
int main() {
    init();
    int vertex_num, edge_num, A, B, C, answer, total_cost;
    while (true) {
        vector< pair<int,int> > graph[MAX];
        priority_queue< pair<int,int> > pq;
        bool visited[MAX] = {false};
        cin >> vertex_num >> edge_num;
        if (vertex_num==0 && edge_num==0) {
            break;
        }
        total_cost = 0;
        for (int i=0; i<edge_num; i++) {
            cin >> A >> B >> C;
            graph[A].push_back(make_pair(B,C));
            graph[B].push_back(make_pair(A,C));
            total_cost += C;
        }
        answer = 0;
        vector< pair<int,int> >::iterator iter;
        for (iter=graph[1].begin(); iter!=graph[1].end(); iter++) {
            pq.push(make_pair(-(iter->second),iter->first));
        }
        visited[1] = true;
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
        cout << (total_cost-answer) << endl;
    }
}