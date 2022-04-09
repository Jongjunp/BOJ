#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
const char house = '1';
const char nothouse = '0';
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main() {
    init();
    int test_num;
    cin >> test_num;
    for (int k=0; k<test_num; k++) {
        int field[50][50] = {nothouse};
        vector<int> group_size;
        bool visited[50][50] = {false};
        int M,N,K;
        cin >> M >> N >> K;
        for (int i=0; i<K; i++) {
            int x,y;
            cin >> x >> y;
            field[x][y] = house;
        }
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (field[i][j]==house && !visited[i][j]) {
                    int size = 1;
                    queue< pair<int,int> > group;
                    pair<int,int> init_home = make_pair(i,j);
                    group.push(init_home);
                    visited[i][j] = true;
                    while (!group.empty()) {
                        pair<int,int> home = group.front();
                        int x = home.first;
                        int y = home.second;
                        group.pop();
                        if (x>0) {
                            if (field[x-1][y]==house && !visited[x-1][y]) {
                                pair<int,int> next_home = make_pair(x-1,y);
                                group.push(next_home);
                                visited[x-1][y] = true;
                                size += 1;
                            }
                        }
                        if (x<M-1){
                            if (field[x+1][y]==house && !visited[x+1][y]) {
                                pair<int,int> next_home = make_pair(x+1,y);
                                group.push(next_home);
                                visited[x+1][y] = true;
                                size += 1;
                            }
                        }
                        if (y>0) {
                            if (field[x][y-1]==house && !visited[x][y-1]) {
                                pair<int,int> next_home = make_pair(x,y-1);
                                group.push(next_home);
                                visited[x][y-1] = true;
                                size += 1;
                            }
                        }
                        if (y<N-1){
                            if (field[x][y+1]==house && !visited[x][y+1]) {
                                pair<int,int> next_home = make_pair(x,y+1);
                                group.push(next_home);
                                visited[x][y+1] = true;
                                size += 1;
                            }
                        }
                    }
                    group_size.push_back(size);
                }
            }
        }
        cout << group_size.size() << endl;
    }
}