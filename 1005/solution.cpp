#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1001;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int T,N,K,A,B;
    cin >> T;
    for (int n=0; n<T; n++) {
        vector<int> graph[MAX];
        queue<int> order;
        int degree[MAX] = {0};
        int cost[MAX] = {0};
        int dp[MAX];
        for (int k=0; k<MAX; k++) {
            dp[k] = -1;
        }
        int min_time = 0;
        int targ_building;
        bool find_targ = false;
        cin >> N >> K;
        for (int i=1; i<=N; i++) {
            cin >> cost[i];
        }
        for (int i=0; i<K; i++) {
            cin >> A >> B;
            degree[B] += 1;
            graph[A].push_back(B);
        }
        cin >> targ_building;
        for (int i=1; i<=N; i++) {
            if (degree[i]==0) {
                order.push(i);
                dp[i] = cost[i];
                if (i==targ_building) {
                    min_time = dp[i];
                    find_targ = true;
                    break;
                }
            }
        }
        if (find_targ) {
            cout << min_time << endl;
            continue;
        }
        for (int i=1; i<=N; i++) {
            if (order.empty()) {
                return 0;
            }
            int x = order.front();
            order.pop();
            for (int j=0; j<graph[x].size(); j++) {
                int y = graph[x][j];
                if (dp[y] < dp[x]) {
                    dp[y] = dp[x];
                }
                if (--degree[y]==0) {
                    order.push(y);
                    dp[y] += cost[y];
                    if (y==targ_building) {
                        min_time = dp[y];
                        find_targ = true;
                    }
                }
                if (find_targ) {
                    break;
                }
            }
            if (find_targ) {
                break;
            }
        }
        cout << min_time << endl;
    }
}