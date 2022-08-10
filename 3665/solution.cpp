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
        vector<int> graph[MAX];
        queue<int> order;
        int degree[MAX] = {0};
        int seq[MAX] = {0};
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> seq[i];
            degree[seq[i]] = i;
            for (int j=0; j<i; j++) {
                graph[seq[i]].push_back(seq[j]);
            }
        }
        cin >> M;
        for (int i=0; i<M; i++) {
            cin >> a >> b;
            vector<int>::iterator iter;
            bool isprecedence = true;
            for (iter=graph[a].begin(); iter!=graph[a].end(); iter++) {
                if (*iter==b) {
                    graph[a].erase(iter);
                    isprecedence = false;
                    break;
                }
            }
            if (!isprecedence) {
                graph[b].push_back(a);
            }
            else {
                for (iter=graph[b].begin(); iter!=graph[b].end(); iter++) {
                    if (*iter==a) {
                        graph[b].erase(iter);
                        break;
                    }
                }
                graph[a].push_back(b);
            }
        }
        for (int i=1; i<=N; i++) {
            
        }
    }
}