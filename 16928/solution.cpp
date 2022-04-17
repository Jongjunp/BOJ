#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
    int N,M;
    int ladder_and_snake[30][2] = {0};
    bool visited[101] = {false};
    cin >> N >> M;
    for (int i=0; i<N+M; i++) {
        cin >> ladder_and_snake[i][0] >> ladder_and_snake[i][1];
    }
    int min_role = 0;
    int init_space = 1;
    int init_role = 0;
    queue< pair<int,int> > q;
    pair<int,int> init_state = make_pair(init_space, init_role);
    q.push(init_state);
    while (!q.empty()) {
        int space = q.front().first;
        int num_role = q.front().second;
        visited[space] = true;
        if (space==100) {
            min_role = num_role;
            break;
        }
        q.pop();
        for (int i=1; i<=6; i++) {
            int new_space = space + i;
            bool is_matched = false;
            for (int k = 0; k<N+M; k++) {
                if (ladder_and_snake[k][0]==new_space) {
                    new_space = ladder_and_snake[k][1];
                    is_matched = true;
                    break;
                }
            }
            if (new_space<=100 && !visited[new_space]) {
                pair<int,int> new_state = make_pair(new_space, num_role+1);
                q.push(new_state);
            }
        }
    }
    cout << min_role << endl;
}