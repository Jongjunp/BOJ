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

bool x_compare(pair< pair<int,int>, pair<int,int> > a, pair< pair<int,int>, pair<int,int> > b) {
    return a.first.second < b.first.second;
}

bool y_compare(pair< pair<int,int>, pair<int,int> > a, pair< pair<int,int>, pair<int,int> > b) {
    return a.second.first < b.second.first;
}

bool z_compare(pair< pair<int,int>, pair<int,int> > a, pair< pair<int,int>, pair<int,int> > b) {
    return a.second.second < b.second.second;
}

int main() {
    init();
    vector< pair<int,int> > graph[MAX];
    vector< pair< pair<int,int>, pair<int,int> > > coord;
    priority_queue< pair<int,int> > pq;
    bool visited[MAX] = {false};
    int vertex_num, x, y, z;
    long long answer = 0;
    cin >> vertex_num;
    for (int i=0; i<vertex_num; i++) {
        cin >> x >> y >> z;
        pair<int,int> yz = make_pair(y,z);
        pair<int,int> ix = make_pair(i,x);
        coord.push_back(make_pair(ix,yz));
    }
    vector< pair< pair<int,int>, pair<int,int> > >::iterator coord_iter;
    for (int i=0; i<3; i++) {
        if (i==0) {
            sort(coord.begin(), coord.end(), x_compare);
        }
        else if (i==1) {
            sort(coord.begin(), coord.end(), y_compare);
        }
        else {
            sort(coord.begin(), coord.end(), z_compare);
        }
        for (coord_iter=coord.begin()+1; coord_iter!=coord.end(); coord_iter++) {
            int vertex1 = ((coord_iter-1)->first).first;
            int vertex2 = ((coord_iter)->first).first;
            int x_diff = abs(((coord_iter-1)->first).second-((coord_iter)->first).second);
            int y_diff = abs(((coord_iter-1)->second).first-((coord_iter)->second).first);
            int z_diff = abs(((coord_iter-1)->second).second-((coord_iter)->second).second);
            vector<int> temp_vec;
            temp_vec.push_back(x_diff);
            temp_vec.push_back(y_diff);
            temp_vec.push_back(z_diff);
            int dist = *min_element(temp_vec.begin(), temp_vec.end());
            graph[vertex1].push_back(make_pair(vertex2,dist));
            graph[vertex2].push_back(make_pair(vertex1,dist));
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