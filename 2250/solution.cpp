#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10001;
const int MAX_LEVEL = 14;
int tree[MAX][2] = {0};
bool ischild[MAX] = {false};
int level_info[MAX_LEVEL][2] = {0};
int max_level = 0;
int max_width = 0;
int cnt = 0;

void dfs(int cur, int level) {
    if (tree[cur][0]!=-1) {
        dfs(tree[cur][0],level+1);
    }
    cnt += 1;
    if (level_info[level][0]>cnt) {
        level_info[level][0] = cnt;
    }
    if (level_info[level][1]<cnt) {
        level_info[level][1] = cnt;
    }
    if (tree[cur][1]!=-1) {
        dfs(tree[cur][1],level+1);
    }
}

int main() {
    int N,node,left,right,root;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> node >> left >> right;
        ischild[left] = true;
        ischild[right] = true;
        tree[node][0] = left;
        tree[node][1] = right;
    }
    for (int i=1; i<=MAX_LEVEL; i++) {
        level_info[i][0] = 20000;
    }
    for (int i=1; i<=N; i++) {
        if (!ischild[i]) {
            root = i;
            break;
        }
    }
    dfs(root,1);
    for (int i=1; i<=MAX_LEVEL; i++) {
        if (level_info[i][1]-level_info[i][0]+1>max_width) {
            max_width = level_info[i][1]-level_info[i][0]+1;
            max_level = i;
        }
    }
    cout << max_level << " " << max_width << endl;
}