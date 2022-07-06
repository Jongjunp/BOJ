#include <iostream>
#include <vector>
#include <queue>
#include <utility>
const int MAX = 1001;
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
//prim algorithm
int main() {
    init();
    int n,m,k,F,T,min_blue,max_blue;
    char C;
    while (true) {
        vector< pair<int,int> > graph[MAX];
        priority_queue< pair<int,int> > max_blue_pq;
        priority_queue< pair<int,int> > min_blue_pq;
        bool max_visited[MAX] = {false};
        bool min_visited[MAX] = {false};
        cin >> n >> m >> k;
        if (n==0 && m==0 && k==0) {
            break;
        }
        for (int i=0; i<m; i++) {
            cin >> C >> F >> T;
            if (C=='B') {
                graph[F].push_back(make_pair(T,1));
                graph[T].push_back(make_pair(F,1));
            }
            else {
                graph[F].push_back(make_pair(T,0));
                graph[T].push_back(make_pair(F,0));
            }
        }
        min_blue = 0;
        max_blue = 0;
        vector< pair<int,int> >::iterator iter;
        for (iter=graph[1].begin(); iter!=graph[1].end(); iter++) {
            min_blue_pq.push(make_pair(-(iter->second),iter->first));
            max_blue_pq.push(make_pair(iter->second,iter->first));
        }
        max_visited[1] = true;
        min_visited[1] = true;
        while(!min_blue_pq.empty()) {
            int weight = -min_blue_pq.top().first;
            int node  = min_blue_pq.top().second;
            min_blue_pq.pop();
            if (min_visited[node]){
                continue;
            }
            min_blue += weight;
            min_visited[node] = true;
            vector< pair<int,int> >::iterator iter;
            for (iter=graph[node].begin(); iter!=graph[node].end(); iter++) {
                min_blue_pq.push(make_pair(-(iter->second),iter->first));
            }
        }
        while(!max_blue_pq.empty()) {
            int weight = max_blue_pq.top().first;
            int node  = max_blue_pq.top().second;
            max_blue_pq.pop();
            if (max_visited[node]){
                continue;
            }
            max_blue += weight;
            max_visited[node] = true;
            vector< pair<int,int> >::iterator iter;
            for (iter=graph[node].begin(); iter!=graph[node].end(); iter++) {
                max_blue_pq.push(make_pair(iter->second,iter->first));
            }
        }
        if (k>=min_blue && k<=max_blue) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}