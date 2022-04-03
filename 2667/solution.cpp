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
    int N;
    int field[25][25] = {0};
    vector<int> group_size;
    bool visited[25][25] = {false};
    cin >> N;
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<str.length(); j++) { 
            if(str[j] == house){
                field[i][j] = house;
            }
            else field[i][j] = nothouse;
        }
    }
    for (int i=0; i<N; i++) {
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
                    if (x<N-1){
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
    sort(group_size.begin(), group_size.end());
    cout << group_size.size() << endl;
    for (int i=0; i<group_size.size(); i++) {
        cout << group_size[i] << endl;
    }
    
}