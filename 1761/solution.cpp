#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_DEPTH = 16;
const int MAX = 40001;
int depth[MAX];
vector< pair<int,int> > adj[MAX];
int parent[MAX][MAX_DEPTH];
void makeTree(int curr) {
    vector<int>::iterator iter;
    for (iter=adj[curr].begin(); iter!=adj[curr].end(); iter++) {
        if (depth[iter->first]==-1) {
            parent[iter->first][0] = curr;
            depth[iter->first] = depth[curr]+1;
            makeTree(iter->first);
        }
    }
}
int main() {
    memset(parent,-1,sizeof(parent));
    memset(depth,-1,sizeof(depth));
    depth[0] = 0;
    int N,M,u,v,w;
    cin >> N;
    for (int i=0; i<N-1; i++) {
        scanf("%d %d %d",&u,&v,&w);
        adj[u-1].push_back(make_pair(v-1,w));
        adj[v-1].push_back(make_pair(u-1,w));
    }
    makeTree(0);
    for (int i=0; i<MAX_DEPTH; i++) {
        for (int j=1; j<N; j++) {
            if (parent[j][i]!=-1) {
                parent[j][i+1] = parent[parent[j][i]][i];
            }
        }
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        scanf("%d %d",&u,&v);
        u--;
        v--;
        if (depth[u]<depth[v]) {
            swap(u,v);
        }
        int dist = 0;
        int diff = depth[u]-depth[v];
        while (diff) {
            dist += adj[u];
            u = parent[u][0];
            diff = depth[u]-depth[v];
        }
        if(u != v){
            while (parent[u][0]!=-1 && parent[u][0]!=parent[v][0]){
                dist += (weights[u][parent[u][0]]+weights[v][parent[v][0]]);
                u = parent[u][0];
                v = parent[v][0];
            }
            dist += (weights[u][parent[u][0]]+weights[v][parent[v][0]]);
        }
        printf("%d\n", dist);
    }
}