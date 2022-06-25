#include <iostream>
#include <queue>
using namespace std;
queue<char> q;
char board[20][20] = ' ';
int main() {
    int R,C;
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> board[i][j];
        }
    }
    while (!q.empty()) {
        
    }
}