#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
vector< pair<int,int> > tree[MAX];
bool visited[MAX] = {false};

pair<int,int> dfs(int cur) {
    visited[cur] = true;
    int max_dist = 0;
    int max_node = cur;
    vector< pair<int,int> >::iterator iter;
    for (iter=tree[cur].begin(); iter!=tree[cur].end(); iter++) {
        if (visited[iter->first]) continue;
        pair<int,int> info = dfs(iter->first);
        if (max_dist<info.first+(iter->second)) {
            max_dist = info.first+(iter->second);
            max_node = info.second;
        }
    }
    return make_pair(max_dist,max_node);
}

int main() {
    int N,node,v,w;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> node;
        while (cin >> v) {
            if (v==-1) {
                break;
            }
            cin >> w;
            tree[node].push_back(make_pair(v,w));
        }
    }
    pair<int,int> first_result = dfs(1);
    memset(visited,false,sizeof(visited));
    pair<int,int> second_result = dfs(first_result.second);
    cout << second_result.first << endl;
}