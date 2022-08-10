#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 501;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int T,N,M,a,b;
    cin >> T;
    for (int t=0; t<T; t++) {
        bool graph[MAX][MAX] = {false};
        queue<int> order;
        int degree[MAX] = {0};
        int seq[MAX] = {0};
        int answer[MAX] = {0};
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> seq[i];
            degree[seq[i]] = i;
            for (int j=0; j<i; j++) {
                graph[seq[i]][seq[j]] = true;
            }
        }
        cin >> M;
        for (int i=0; i<M; i++) {
            cin >> a >> b;
            if (graph[a][b]) {
                graph[a][b] = false;
                degree[a] -= 1;
                graph[b][a] = true;
                degree[b] += 1;
            }
            else {
                graph[a][b] = true;
                degree[a] += 1;
                graph[b][a] = false;
                degree[b] -= 1;
            }
        }
        for (int i=1; i<=N; i++) {
            if (degree[i]==0) {
                order.push(i);
                break;
            }
        }
        bool abnormal = false;
        for (int i=1; i<=N; i++) {
            if (order.empty()) {
                cout << "IMPOSSIBLE\n";
                abnormal = true;
                break;
            }
            else if (order.size()!=1) {
                cout << "?\n";
                abnormal = true;
                break;
            }
            int x = order.front();
            answer[i] = x;
            order.pop();
            for (int j=1; j<=N; j++) {
                if (graph[j][x] && (--degree[j]==0)) {
                    order.push(j);
                }
            }
        }
        if (!abnormal) {
            for (int i=1; i<=N; i++) {
                cout << answer[i] << " ";
            }
            cout << "\n";
        }
    }
}