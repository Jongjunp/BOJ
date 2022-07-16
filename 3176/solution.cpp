#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_DEPTH = 18;
const int MAX = 100001;
const int MAX_VAL = 0;
const int MIN_VAL = 1000001;
int depth[MAX];
vector< pair<int,int> > adj[MAX];
int parent[MAX][MAX_DEPTH];
int maxarr[MAX][MAX_DEPTH];
int minarr[MAX][MAX_DEPTH];
void makeTree(int curr) {
    vector< pair<int,int> >::iterator iter;
    for (iter=adj[curr].begin(); iter!=adj[curr].end(); iter++) {
        if (depth[iter->first]==-1) {
            parent[iter->first][0] = curr;
            maxarr[iter->first][0] = iter->second;
            minarr[iter->first][0] = iter->second;
            depth[iter->first] = depth[curr]+1;
            makeTree(iter->first);
        }
    }
}
int main() {
    memset(parent,-1,sizeof(parent));
    memset(depth,-1,sizeof(depth));
    memset(maxarr,-1,sizeof(maxarr));
    memset(minarr,-1,sizeof(minarr));
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
                maxarr[j][i+1] = max(maxarr[parent[j][i]][i],maxarr[j][i]);
                minarr[j][i+1] = min(minarr[parent[j][i]][i],minarr[j][i]);
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
        int ans_max = MAX_VAL;
        int ans_min = MIN_VAL;
        while (diff) {
            if (diff%2) {
                ans_max = max(maxarr[u][p],ans_max);
                ans_min = min(minarr[u][p],ans_min);
                u = parent[u][p];
            }
            p += 1;
            diff /= 2;
        }
        if(u != v){
            for(int j=MAX_DEPTH-1; j>=0; j--){
                if(parent[u][j]!=-1 && parent[u][j]!=parent[v][j]){
                    ans_max = max(maxarr[u][j],ans_max);
                    ans_max = max(maxarr[v][j],ans_max);
                    ans_min = min(minarr[u][j],ans_min);
                    ans_min = min(minarr[v][j],ans_min);
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            ans_max = max(maxarr[u][0],ans_max);
            ans_max = max(maxarr[v][0],ans_max);
            ans_min = min(minarr[u][0],ans_min);
            ans_min = min(minarr[v][0],ans_min);
        }
        printf("%d %d\n",ans_min,ans_max);
    }
}