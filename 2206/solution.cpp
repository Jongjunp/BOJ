#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

const char block = '1';
const char blank = '0';

int main() {
    int height, width;
    char board[1000][1000] = {'0'};
    cin >> height >> width;

    string row;
    for (int i=0; i<height; i++) {
        scanf("%s",board[i]);
    }

    //BFS
    queue< pair< pair<int,int>, pair<int,bool> > > state_queue;
    bool visited[1000][1000][2] = {false};
    visited[0][0][0] = true; 
    pair< pair<int,int>, pair<int,int> >init_state = make_pair(make_pair(0,0),make_pair(1,0));
    int min_action_num = -1;
    bool reachable = false;
    state_queue.push(init_state);
    while (!state_queue.empty()) {
        pair< pair<int,int>, pair<int,int> > state = state_queue.front();
        pair<int,int> coord = state.first;
        pair<int,int> substate = state.second;
        state_queue.pop();
       
        int h = coord.first;
        int w = coord.second;
        int dist = substate.first;
        int breaked = substate.second;

        //left action
        if (w!=0) {
            if ((board[h][w-1]==blank) 
                && ((h+1<height) && (board[h+1][w]!=blank))
                && (!visited[h][w-1][breaked])) {
                visited[h][w-1][breaked] = true;
                pair< pair<int,int>, pair<int,int> > left_state = make_pair(make_pair(h,w-1), make_pair(dist+1, breaked));
                state_queue.push(left_state);
            }
        }
        //right action
        if (w!=width-1) {
            if ((h==height-1) && (w+1==width-1)) {
                min_action_num = dist+1;
                reachable = true;
                break;
            }
            else {
                if ((breaked==0) && (board[h][w+1]==block)) {
                    visited[h][w+1][breaked+1] = true;
                    pair< pair<int,int>, pair<int,int> > right_state = make_pair(make_pair(h,w+1), make_pair(dist+1, breaked+1));
                    state_queue.push(right_state);
                }
                else if ((board[h][w+1]==blank) && (!visited[h][w+1][breaked])) {
                    visited[h][w+1][breaked] = true;
                    pair< pair<int,int>, pair<int,int> > right_state = make_pair(make_pair(h,w+1), make_pair(dist+1, breaked));
                    state_queue.push(right_state);
                }
            }
        }
        //up action
        if (h!=0) {
            if (board[h-1][w]==blank
                && ((w+1<width) && (board[h][w+1]!=blank))
                && (!visited[h-1][w][breaked])) {
                visited[h-1][w][breaked] = true;
                pair< pair<int,int>, pair<int,int> > up_state = make_pair(make_pair(h-1,w), make_pair(dist+1, breaked));
                state_queue.push(up_state);
                }
        }
        //down action
        if (h!=height-1) {
            if ((h+1==height-1) && (w==width-1)) {
                min_action_num = dist+1;
                reachable = true;
                break;
            }
            else {
                if ((breaked==0) && (board[h+1][w]==block)) {
                        visited[h+1][w][breaked+1] = true;
                        pair< pair<int,int>, pair<int,int> > down_state = make_pair(make_pair(h+1,w), make_pair(dist+1, breaked+1));
                        state_queue.push(down_state);
                    }
                else if ((board[h+1][w]==blank) && (!visited[h+1][w][breaked])) {
                    visited[h+1][w][breaked] = true;
                    pair< pair<int,int>, pair<int,int> > down_state = make_pair(make_pair(h+1,w), make_pair(dist+1, breaked));
                    state_queue.push(down_state);
                }
            }
        }
        
    }
    if (height==1 && width==1){
        cout << 1 << endl;
    }
    else {
        cout << min_action_num << endl;
    }
}