#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_DEPTH = 18; //round log_2(100000)
const int MAX = 100001;
//1. depth array
int depth[MAX];
//2. adjacent matrix with table
vector<int> adj[MAX];
//3. sparse parent matrix
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
        cin >> u >> v;
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
        cin >> u >> v;
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
        //depth[u] becomes equal to depth[v]
        if(u != v){
            for(int j=MAX_DEPTH-1; j>=0; j--){
                if(parent[u][j] != -1 && parent[u][j]!=parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        cout << u+1 << endl;
    }
}