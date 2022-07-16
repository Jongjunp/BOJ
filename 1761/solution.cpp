#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_DEPTH = 17;
const int MAX = 40001;
int depth[MAX];
vector< pair<int,int> > adj[MAX];
int parent[MAX][MAX_DEPTH];
int dist[MAX][MAX_DEPTH];
void makeTree(int curr) {
    vector< pair<int,int> >::iterator iter;
    for (iter=adj[curr].begin(); iter!=adj[curr].end(); iter++) {
        if (depth[iter->first]==-1) {
            parent[iter->first][0] = curr;
            dist[iter->first][0] = iter->second;
            depth[iter->first] = depth[curr]+1;
            makeTree(iter->first);
        }
    }
}
int main() {
    memset(parent,-1,sizeof(parent));
    memset(depth,-1,sizeof(depth));
    memset(dist,-1,sizeof(dist));
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
                dist[j][i+1] = dist[parent[j][i]][i]+dist[j][i];
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
        int diff = depth[u]-depth[v];
        int p = 0;
        int answer = 0;
        while (diff) {
            if (diff%2) {
                answer += dist[u][p];
                u = parent[u][p];
            }
            p += 1;
            diff /= 2;
        }
        if(u != v){
            for(int j=MAX_DEPTH-1; j>=0; j--){
                if(parent[u][j]!=-1 && parent[u][j]!=parent[v][j]){
                    answer += dist[u][j];
                    answer += dist[v][j];
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            answer += dist[u][0];
            answer += dist[v][0];
        }
        printf("%d\n",answer);
    }
}