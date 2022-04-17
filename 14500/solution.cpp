#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
    int N,M;
    int field[500][500] = {0};
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> field[i][j];
        }
    }
    int max_sum = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int init_num_block = 1;
            int init_sum = field[i][j];
            queue< pair< pair< pair<int,int>, pair<int,int> >, pair<int,int> > > tetromino_q;
            pair<int,int> sub_init1 = make_pair(init_num_block,init_sum);
            pair<int,int> sub_init2 = make_pair(i,j);
            pair< pair<int,int>, pair<int,int> > temp_init = make_pair(sub_init1, sub_init2);
            pair<int,int> prev = make_pair(i,j);
            pair< pair< pair<int,int>, pair<int,int> >, pair<int,int> > init = make_pair(temp_init, prev);
            tetromino_q.push(init);
            if (i>0 && i<N-1 && j>0) {
                int tetromino_sum = field[i][j]+field[i-1][j]+field[i+1][j]+field[i][j-1];
                if (tetromino_sum > max_sum) {
                    max_sum = tetromino_sum;
                }
            }
            if (i>0 && i<N-1 && j<M-1) {
                int tetromino_sum = field[i][j]+field[i-1][j]+field[i+1][j]+field[i][j+1];
                if (tetromino_sum > max_sum) {
                    max_sum = tetromino_sum;
                }
            }
            if (i>0 && j>0 && j<M-1) {
                int tetromino_sum = field[i][j]+field[i-1][j]+field[i][j-1]+field[i][j+1];
                if (tetromino_sum > max_sum) {
                    max_sum = tetromino_sum;
                }
            }
            if ( i<N-1 && j>0 && j<M-1) {
                int tetromino_sum = field[i][j]+field[i+1][j]+field[i][j-1]+field[i][j+1];
                if (tetromino_sum > max_sum) {
                    max_sum = tetromino_sum;
                }
            }
            while (!tetromino_q.empty()) {
                int num_block = tetromino_q.front().first.first.first;
                int sum = tetromino_q.front().first.first.second;
                int x = tetromino_q.front().first.second.first;
                int y = tetromino_q.front().first.second.second;
                int prev_x = tetromino_q.front().second.first;
                int prev_y = tetromino_q.front().second.second;
                if (num_block==4 && max_sum < sum) {
                    max_sum = sum;
                }
                tetromino_q.pop();
                if (num_block<4) {
                    if (x>0 && x-1!=prev_x) {
                        pair<int,int> sub_info1 = make_pair(num_block+1, sum+field[x-1][y]);
                        pair<int,int> sub_info2 = make_pair(x-1, y);
                        pair< pair<int,int>, pair<int,int> > temp_info = make_pair(sub_info1, sub_info2);
                        pair<int,int> prev = make_pair(x,y);
                        pair< pair< pair<int,int>, pair<int,int> >, pair<int,int> > info = make_pair(temp_info, prev);
                        tetromino_q.push(info);
                    }
                    if (x<M-1 && x+1!=prev_x) {
                        pair<int,int> sub_info1 = make_pair(num_block+1, sum+field[x+1][y]);
                        pair<int,int> sub_info2 = make_pair(x+1, y);
                        pair< pair<int,int>, pair<int,int> > temp_info = make_pair(sub_info1, sub_info2);
                        pair<int,int> prev = make_pair(x,y);
                        pair< pair< pair<int,int>, pair<int,int> >, pair<int,int> > info = make_pair(temp_info, prev);
                        tetromino_q.push(info);
                    }
                    if (y>0 && y-1!=prev_y) {
                        pair<int,int> sub_info1 = make_pair(num_block+1, sum+field[x][y-1]);
                        pair<int,int> sub_info2 = make_pair(x, y-1);
                        pair< pair<int,int>, pair<int,int> > temp_info = make_pair(sub_info1, sub_info2);
                        pair<int,int> prev = make_pair(x,y);
                        pair< pair< pair<int,int>, pair<int,int> >, pair<int,int> > info = make_pair(temp_info, prev);
                        tetromino_q.push(info);
                    }
                    if (y<N-1 && y+1!=prev_y) {
                        pair<int,int> sub_info1 = make_pair(num_block+1, sum+field[x][y+1]);
                        pair<int,int> sub_info2 = make_pair(x, y+1);
                        pair< pair<int,int>, pair<int,int> > temp_info = make_pair(sub_info1, sub_info2);
                        pair<int,int> prev = make_pair(x,y);
                        pair< pair< pair<int,int>, pair<int,int> >, pair<int,int> > info = make_pair(temp_info, prev);
                        tetromino_q.push(info);
                    }
                }
            }
        }
    }
    cout << max_sum << endl;
}