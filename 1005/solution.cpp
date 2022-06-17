#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T,N,K,v1,v2,W;
int build_time[1001] = {0};
vector<int> dependency[1001];
bool visited[1001] = {false};
int topological_sort(int goal) {
    queue<int> built;
    for (int i=0; i<N; i++) {

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> K;
        for (int j=1; j<=N; j++) {
            cin >> build_time[j];
            dependency[j].clear();
        }
        for (int k=0; k<K; k++) {
            cin >> v1 >> v2;
            dependency[v2].push_back(v1);
        }
        cin >> W;
        cout >> topological_sort(W) >> endl;
    }
}