#include <iostream>
#include <queue>
#include <utility>
#include <set>
using namespace std;
const char wall = '1';
const char space = '0';
int main() {
    int N,M;
    char field[1000][1000];
    int temp_answer[1000][1000] = {0};
    short temp_group[500002] = {0};
    bool visited[1000][1000] = {false};
    bool filled[1000][1000] = {false};
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> field[i][j];
        }
    }
    int group = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (field[i][j]==space && !visited[i][j]) {
                short cnt = 1;
                visited[i][j] = true;
                queue< pair<int,int> > q;
                pair<int,int> loc = make_pair(i,j);
                q.push(loc);
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if (x>0) {
                        if (field[x-1][y]!=wall && !visited[x-1][y]) {
                            pair<int,int> new_loc = make_pair(x-1,y);
                            q.push(new_loc);
                            visited[x-1][y] = true;
                            cnt += 1;
                            cnt = cnt%10;
                        }
                    }
                    if (x<N-1) {
                        if (field[x+1][y]!=wall && !visited[x+1][y]) {
                            pair<int,int> new_loc = make_pair(x+1,y);
                            q.push(new_loc);
                            visited[x+1][y] = true;
                            cnt += 1;
                            cnt = cnt%10;
                        }
                    }
                    if (y>0) {
                        if (field[x][y-1]!=wall && !visited[x][y-1]) {
                            pair<int,int> new_loc = make_pair(x,y-1);
                            q.push(new_loc);
                            visited[x][y-1] = true;
                            cnt += 1;
                            cnt = cnt%10;
                        }
                    }
                    if (y<M-1) {
                        if (field[x][y+1]!=wall && !visited[x][y+1]) {
                            pair<int,int> new_loc = make_pair(x,y+1);
                            q.push(new_loc);
                            visited[x][y+1] = true;
                            cnt += 1;
                            cnt = cnt%10;
                        }
                    }
                }
                short fill = cnt%10;
                temp_group[group] = fill;
                temp_answer[i][j] = group;
                filled[i][j] = true;
                queue< pair<int,int> > q2;
                pair<int,int> init_loc = make_pair(i,j);
                q2.push(init_loc);
                while (!q2.empty()) {
                    int x = q2.front().first;
                    int y = q2.front().second;
                    q2.pop();
                    if (x>0) {
                        if (field[x-1][y]!=wall && !filled[x-1][y]) {
                            pair<int,int> new_loc = make_pair(x-1,y);
                            q2.push(new_loc);
                            filled[x-1][y] = true;
                            temp_answer[x-1][y] = group;
                        }
                    }
                    if (x<N-1) {
                        if (field[x+1][y]!=wall && !filled[x+1][y]) {
                            pair<int,int> new_loc = make_pair(x+1,y);
                            q2.push(new_loc);
                            filled[x+1][y] = true;
                            temp_answer[x+1][y] = group;
                        }
                    }
                    if (y>0) {
                        if (field[x][y-1]!=wall && !filled[x][y-1]) {
                            pair<int,int> new_loc = make_pair(x,y-1);
                            q2.push(new_loc);
                            filled[x][y-1] = true;
                            temp_answer[x][y-1] = group;
                        }
                    }
                    if (y<M-1) {
                        if (field[x][y+1]!=wall && !filled[x][y+1]) {
                            pair<int,int> new_loc = make_pair(x,y+1);
                            q2.push(new_loc);
                            filled[x][y+1] = true;
                            temp_answer[x][y+1] = group;
                        }
                    }
                }
                group += 1;
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (field[i][j]==wall) {
                int answer = 1;
                set<int> temp_set;
                if (i>0) {
                    temp_set.insert(temp_answer[i-1][j]);
                }
                if (i<N-1) {
                    temp_set.insert(temp_answer[i+1][j]);
                }
                if (j>0) {
                    temp_set.insert(temp_answer[i][j-1]);
                }
                if (j<M-1) {
                    temp_set.insert(temp_answer[i][j+1]);
                }
                set<int>::iterator iter;
                for (iter=temp_set.begin(); iter!=temp_set.end(); iter++) {
                    answer += temp_group[*iter];
                    answer = answer%10;
                }
                cout << answer;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }
}