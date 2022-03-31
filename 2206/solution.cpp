#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

const char block = '1';
const char blank = '0';
const int INF = 100000000;

int main() {
    int height, width;
    char board[1000][1000] = {'0'};
    cin >> height >> width;

    string row;
    for (int i=0; i<height; i++) {
        cin >> row;
        strcpy(board[i],row.c_str());
    }

    pair<int,int> start = make_pair(0,0);
    pair<int,int> goal = make_pair(height-1, width-1);

    //BFS
    queue< pair< pair< pair<int,int>,int >, bool> > state_queue;
    list< pair<int,int> > visited;
    pair < pair<int,int>, int > init_substate = make_pair(start,1);
    pair< pair< pair<int,int>, int >, bool> init_state = make_pair(init_substate, false);
    int min_action_num = INF;
    bool reachable = true;
    visited.push_back(start);
    state_queue.push(init_state);
    while (!state_queue.empty()) {
        pair< pair< pair<int,int>, int >, bool> state = state_queue.front();
        pair< pair<int,int>, int > sub_state = state.first;
        pair<int,int> coord = sub_state.first;
        int dist = sub_state.second;
        bool breaked = state.second;
        state_queue.pop();
       
        int h = coord.first;
        int w = coord.second;

        //left action
        if (w!=0) {
            if (board[h][w-1]==blank) {
                pair<int,int> left_coord = make_pair(h,w-1);
                if (find(visited.begin(), visited.end(), left_coord)==visited.end()) {
                    pair< pair<int,int>, int > left_substate = make_pair(left_coord,dist+1);
                    pair< pair< pair<int,int>, int >, bool> left_state = make_pair(left_substate,breaked);
                    state_queue.push(left_state);
                    visited.push_back(left_coord);
                }
                else {
                    reachable = false;
                }
            }
            else {
                if (!breaked) {
                    pair<int,int> left_coord = make_pair(h,w-1);
                    if (find(visited.begin(), visited.end(), left_coord)==visited.end()) {
                        pair< pair<int,int>, int > left_substate = make_pair(left_coord,dist+1);
                        pair< pair< pair<int,int>, int >, bool> left_state = make_pair(left_substate,true);
                        state_queue.push(left_state);
                        visited.push_back(left_coord);
                    }
                    else {
                        reachable = false;
                    }
                }
                else{
                    reachable = false;
                }
            }
        }
        //right action
        if (w!=width-1) {
            if ((h==height-1) && (w+1==width-1)) {
                if (min_action_num > dist+1){
                    min_action_num = dist+1;
                }
                reachable = true;
                break;
            }
            else {
                if (board[h][w+1]==blank) {
                    pair<int,int> right_coord = make_pair(h,w+1);
                    if (find(visited.begin(), visited.end(), right_coord)==visited.end()) {
                        pair< pair<int,int>, int > right_substate = make_pair(right_coord,dist+1);
                        pair< pair< pair<int,int>, int >, bool> right_state = make_pair(right_substate,breaked);
                        state_queue.push(right_state);
                        visited.push_back(right_coord);
                    }
                    else {
                        reachable = false;
                    }
                }
                else {
                    if (!breaked) {
                        pair<int,int> right_coord = make_pair(h,w+1);
                        if (find(visited.begin(), visited.end(), right_coord)==visited.end()) {
                            pair< pair<int,int>, int > right_substate = make_pair(right_coord,dist+1);
                            pair< pair< pair<int,int>, int >, bool> right_state = make_pair(right_substate,true);
                            state_queue.push(right_state);
                            visited.push_back(right_coord);
                        }
                        else {
                            reachable = false;
                        }
                    }
                    else {
                        reachable = false;
                    }
                }
            }
        }
        //up action
        if (h!=0) {
            if (board[h-1][w]==blank) {
                pair<int,int> up_coord = make_pair(h-1,w);
                if (find(visited.begin(), visited.end(), up_coord)==visited.end()) {
                    pair< pair<int,int>, int > up_substate = make_pair(up_coord,dist+1);
                    pair< pair< pair<int,int>, int >, bool> up_state = make_pair(up_substate,breaked);
                    state_queue.push(up_state);
                    visited.push_back(up_coord);
                }
                else {
                    reachable = false;
                }
            }
            else {
                if (!breaked) {
                    pair<int,int> up_coord = make_pair(h-1,w);
                    if (find(visited.begin(), visited.end(), up_coord)==visited.end()) {
                        pair< pair<int,int>, int > up_substate = make_pair(up_coord,dist+1);
                        pair< pair< pair<int,int>, int >, bool> up_state = make_pair(up_substate,true);
                        state_queue.push(up_state);
                        visited.push_back(up_coord);
                    }
                    else {
                        reachable = false;
                    }
                }
                else{
                    reachable = false;
                }
            }
        }
        //down action
        if (h!=height-1) {
            if ((h+1==height-1) && (w==width-1)) {
                if (min_action_num > dist+1){
                    min_action_num = dist+1;
                }
                reachable = true;
                break;
            }
            else {
                if (board[h+1][w]==blank) {
                    pair<int,int> down_coord = make_pair(h+1,w);
                    if (find(visited.begin(), visited.end(), down_coord)==visited.end()) {
                        pair< pair<int,int>, int > down_substate = make_pair(down_coord,dist+1);
                        pair< pair< pair<int,int>, int >, bool> down_state = make_pair(down_substate,breaked);
                        state_queue.push(down_state);
                        visited.push_back(down_coord);
                    }
                    else {
                        reachable = false;
                    }
                }
                else {
                    if (!breaked) {
                        pair<int,int> down_coord = make_pair(h+1,w);
                        if (find(visited.begin(), visited.end(), down_coord)==visited.end()) {
                            pair< pair<int,int>, int > down_substate = make_pair(down_coord,dist+1);
                            pair< pair< pair<int,int>, int >, bool> down_state = make_pair(down_substate,true);
                            state_queue.push(down_state);
                            visited.push_back(down_coord);
                        }
                        else {
                            reachable = false;
                        }
                    }
                    else {
                        reachable = false;
                    }
                }
            }
        }
        
    }

    if (!reachable) {
        cout << -1 << endl;
    }
    else {
        cout << min_action_num << endl;
    }
}