#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char board[20][20];
bool visited[26] = {false};
int max_len = 0;
int R,C;

void DFS(int h, int w, int cnt) {
    if (cnt > max_len) {
        max_len = cnt;
    }
    for (int i=0; i<4; i++) {
        char next_char;
        if ((h+dx[i])>=0 && (h+dx[i])<R && (w+dy[i])>=0 && (w+dy[i])<C) {
            next_char = board[h+dx[i]][w+dy[i]];
        }
        else {
            continue;
        }
        if (visited[next_char-'A']) {
            continue;
        }
        else {
            int next_h = h+dx[i];
            int next_w = w+dy[i];
            visited[next_char-'A'] = true;
            DFS(next_h,next_w,cnt+1);
            visited[next_char-'A'] = false;
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> board[i][j];
        }
    }
    visited[board[0][0]-'A'] = true;
    DFS(0,0,1);
    cout << max_len << endl;
}