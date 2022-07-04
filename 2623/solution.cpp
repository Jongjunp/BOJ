#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1001;
vector<int> graph[MAX];
queue<int> order;
int degree[MAX] = {0};
int result[MAX] = {0};
int temp[MAX*100] = {0};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int N,M,K,A;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> K;
        for (int j=0; j<K; j++) {
            cin >> temp[j];
        }
        for (int j=1; j<K; j++) {
            degree[temp[j]] += 1;
            graph[temp[j-1]].push_back(temp[j]);
        }
    }
    for (int i=1; i<=N; i++) {
        if (degree[i]==0) {
            order.push(i);
        }
    }
    for (int i=1; i<=N; i++) {
        if (order.empty()) {
            cout << 0 << endl;
            return 0;
        }
        int x = order.front();
        order.pop();
        result[i] = x;
        for (int j=0; j<graph[x].size(); j++) {
            int y = graph[x][j];
            if (--degree[y]==0) {
                order.push(y);
            }
        }
    }
    for (int i=1; i<=N; i++) {
        cout << result[i] << endl;
    }
}