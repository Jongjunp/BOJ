#include <iostream>
using namespace std;
const int MAX = 501;
int map[MAX][MAX] = {0};
int dp[MAX][MAX] = {0};
int N,M;

int dfs(int x, int y) {
    if (x==M-1 && y==N-1) return 1;
    if (dp[x][y]!=-1) return dp[x][y]; 
    dp[x][y] = 0;
    int val = map[x][y];
    if (x>0 && val>map[x-1][y]) {
        dp[x][y] = dp[x][y] + dfs(x-1,y);
    }
    if (y>0 && val>map[x][y-1]) {
        dp[x][y] = dp[x][y] + dfs(x,y-1);
    }
    if (x<M-1 && val>map[x+1][y]) {
        dp[x][y] = dp[x][y] + dfs(x+1,y);
    }
    if (y<N-1 && val>map[x][y+1]) {
        dp[x][y] = dp[x][y] + dfs(x,y+1);
    }
    return dp[x][y];
}

int main() {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> M >> N;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    int answer = dfs(0,0);
    cout << answer << endl;
}