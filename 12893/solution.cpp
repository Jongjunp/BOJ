#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 2001;
vector<int> graph[MAX];
int color[MAX] = {0};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int N,M,A,B;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    queue<int> q;
    bool isbipartite = true;
    for (int l=1; l<=N; l++) {
        if (color[l]==0) {
            q.push(l);
            color[l] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                vector<int>::iterator iter;
                for (iter=graph[node].begin(); iter!=graph[node].end(); iter++) {
                    if (color[*iter]==0) {
                        q.push(*iter);
                        if (color[node]==1) {
                            color[*iter] = 2;
                        }
                        else {
                            color[*iter] = 1;
                        }
                    }
                    else if (color[*iter]==color[node]) {
                        isbipartite = false;
                        break;
                    }
                }
                if (!isbipartite) {
                    break;
                }
            }
            if (!isbipartite) {
                break;
            }
        }
    }
    if (isbipartite) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}