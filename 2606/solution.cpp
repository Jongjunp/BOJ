#include <iostream>
#include <queue>
using namespace std;

int main() {
    int numComp, numEdge;
    queue<int> q;
    q.push(0);
    cin >> numComp;
    cin >> numEdge;
    bool visited[100] = {false};
    int connected[100][100] = {{false}};
    for (int i=0; i<numEdge; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        connected[src-1][dest-1] = true;
        connected[dest-1][src-1] = true;
    }
    while (!q.empty()) {
        for (int j=0; j<numComp; j++) {
            if (connected[q.front()][j] && !visited[q.front()]) {
                q.push(j);
            }
        }
        visited[q.front()] = true;
        q.pop();
    }
    int cnt = 0;
    for (int k=1; k<numComp; k++) {
        if (visited[k]) {
            cnt += 1;
        }
    }
    cout << cnt << endl;
}