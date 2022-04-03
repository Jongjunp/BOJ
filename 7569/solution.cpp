#include <iostream>
#include <queue>
#include <utility>
using namespace std;
const int riped = 1;
const int nonriped = 0;
const int nottomato = -1;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main() {
    init();
    int M,N,H;
    int box[100][100][100];
    bool visited[100][100][100] = {false};
    int tomato_num = 0;
    int day = 0;
    cin >> M >> N >> H;
    queue< pair< pair<int,int>, pair<int,int> > > riped_list;
    for (int h=0; h<H; h++) {
        for (int n=0; n<N; n++) {
            for (int m=0; m<M; m++) {
                int tomato;
                cin >> tomato;
                if (tomato==riped) {
                    pair<int,int> pair1 = make_pair(m,n);
                    pair<int,int> pair2 = make_pair(h,day);
                    pair< pair<int,int>, pair<int,int> > riped_tomato = make_pair(pair1, pair2);
                    riped_list.push(riped_tomato);
                    visited[m][n][h] = true;
                }
                if (tomato!=nottomato) {
                    tomato_num += 1;
                }
                box[m][n][h] = tomato;
            }
        }
    }
    //BFS
    while (!riped_list.empty()){
        pair< pair<int,int>, pair<int,int> > square = riped_list.front();
        int m = square.first.first;
        int n = square.first.second;
        int h = square.second.first;
        int d = square.second.second;
        if (d > day) {
            day = d;
        }
        int dir[2] = {-1,1};
        int limits[6] = {0,M-1,0,N-1,0,H-1};
        riped_list.pop();
        for (int i=0; i<3; i++) {
            for (int j=0; j<2; j++) {
                int new_coord[3] = {m,n,h};
                int limit = limits[j+(2*i)];
                new_coord[i] += dir[j];
                bool cond;
                if (j==0) {
                    cond = new_coord[i]>=limit;
                }
                else {
                    cond = new_coord[i]<=limit;
                }
                if (cond) {
                    if (!visited[new_coord[0]][new_coord[1]][new_coord[2]] && box[new_coord[0]][new_coord[1]][new_coord[2]]==nonriped) {
                        pair<int,int> pair1 = make_pair(new_coord[0],new_coord[1]);
                        pair<int,int> pair2 = make_pair(new_coord[2],d+1);
                        pair< pair<int,int>, pair<int,int> > new_square = make_pair(pair1, pair2);
                        riped_list.push(new_square);
                        visited[new_coord[0]][new_coord[1]][new_coord[2]] = true;
                    }
                }
            }
        }
    }
    int riped_fin = 0;
    for (int h=0; h<H; h++) {
        for (int n=0; n<N; n++) {
            for (int m=0; m<M; m++) {
                if (visited[m][n][h]) {
                    riped_fin += 1;
                }
            }
        }
    }
    if (riped_fin==tomato_num) {
        cout << day << endl;
    }
    else {
        cout << -1 << endl;
    }
}