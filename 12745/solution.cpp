#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_DEPTH = 12;
const int MAX = 2223;
int depth[MAX];
vector<int> adj[MAX];
int cntparent[MAX][MAX] = {0};
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
    int N,Q,u,v;
    int a = 0;
    int b = 0;
    int answer = 0;
    cin >> N >> Q;
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
    for (int i=0; i<Q; i++) {
        scanf("%d %d",&u,&v);
        u--;
        v--;
        if (depth[u]<depth[v]) {
            swap(u,v);
        }
        int diff = depth[u]-depth[v];
        while (diff) {
            cntparent[u][parent[u][0]] += 1;
            if (answer < cntparent[u][parent[u][0]]) {
                answer = cntparent[u][parent[u][0]];
                a = u;
                b = parent[u][0];
            }
            u = parent[u][0];
            diff = depth[u]-depth[v];
        }
        if(u != v){
            while (parent[u][0]!=-1 && parent[u][0]!=parent[v][0]){
                cntparent[u][parent[u][0]] += 1;
                cntparent[v][parent[v][0]] += 1;
                if (answer < cntparent[u][parent[u][0]]) {
                    answer = cntparent[u][parent[u][0]];
                    a = u;
                    b = parent[u][0];
                }
                if (answer < cntparent[v][parent[v][0]]) {
                    answer = cntparent[v][parent[v][0]];
                    a = v;
                    b = parent[v][0];
                }
                u = parent[u][0];
                v = parent[v][0];
            }
            cntparent[u][parent[u][0]] += 1;
            cntparent[v][parent[v][0]] += 1;
            if (answer < cntparent[u][parent[u][0]]) {
                answer = cntparent[u][parent[u][0]];
                a = u;
                b = parent[u][0];
            }
            if (answer < cntparent[v][parent[v][0]]) {
                answer = cntparent[v][parent[v][0]];
                a = v;
                b = parent[v][0];
            }
            u = parent[u][0];
            v = parent[v][0];
        }
    }
    printf("%d %d %d\n", min(a+1,b+1), max(a+1,b+1), answer);
}