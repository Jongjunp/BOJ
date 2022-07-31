#include <iostream>
using namespace std;
const int MAX = 51;
int tree[MAX] = {0};
int N,targ,root;
int answer = 0;

void dfs(int cur) {
    int cnt = 0;
    if (cur==targ) return;
    for (int i=0; i<N; i++) {
        if (tree[i]==cur && i!=targ) {
            cnt += 1;
            dfs(i);
        }
    }
    if (cnt==0) {
        answer += 1;
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> tree[i];
        if (tree[i]==-1) {
            root = i;
        }
    }
    cin >> targ;
    dfs(root);
    cout << answer << endl;
}