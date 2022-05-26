#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_DEPTH = 18;
const int MAX = 100001;
int depth[MAX];
vector<int> adj[MAX];
int parent[MAX][MAX_DEPTH];
void makeTree(int curr) {
    vector<int>::iterator iter;
    for (iter=adj[curr].begin(); iter!=adj[curr].end(); iter++) {
        if (depth[*iter]==-1) {
            parent[*iter][0] = curr;
            depth[*iter] = depth[curr]+1;
            makeTree(*iter);
        }
    }
}
int main() {
    memset(parent,-1,sizeof(parent));
    memset(depth,-1,sizeof(depth));
    depth[0] = 0;
    int N,M,u,v;
    cin >> N;
    for (int i=0; i<N-1; i++) {
        scanf("%d %d",&u,&v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
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
        int diff = depth[u]-depth[v];
        int p = 0;
        while (diff) {
            if (diff%2) {
                u = parent[u][p];
            }
            p += 1;
            diff /= 2;
        }
        if(u != v){
            for(int j=MAX_DEPTH-1; j>=0; j--){
                if(parent[u][j] != -1 && parent[u][j]!=parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        printf("%d\n",u+1);
    }
}