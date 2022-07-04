#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 32001;
vector<int> graph[MAX];
queue<int> order;
int degree[MAX] = {0};
int result[MAX] = {0};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int N,M,A,B;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B;
        degree[B] += 1;
        graph[A].push_back(B);
    }
    for (int i=1; i<=N; i++) {
        if (degree[i]==0) {
            order.push(i);
        }
    }
    for (int i=1; i<=N; i++) {
        if (order.empty()) {
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
        cout << result[i] << " ";
    }
    cout << endl;
}