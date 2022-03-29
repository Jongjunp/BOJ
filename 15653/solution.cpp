#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

const char block = '#';
const char blank = '.';
const char hole = 'O';
const char red = 'R';
const char blue = 'B';

pair< pair<int,int>,pair<int,int> > Left(char arr[][10], int red_h, int red_w, int blue_h, int blue_w) {
    int red_result = red_w;
    int blue_result = blue_w;
    if (red_h == blue_h) {
        if (red_w < blue_w) {
            while (arr[red_h][red_result-1]==blank) {
                red_result -= 1;
            }
            if (arr[red_h][red_result-1]==hole) {
                red_result -= 1;
            }
            while ((arr[blue_h][blue_result-1]==blank) && (blue_result-1 != red_result)) {
                blue_result -= 1;
            }
            if (arr[blue_h][blue_result-1]==hole) {
                blue_result -= 1;
            }
        }
        else {
            while (arr[blue_h][blue_result-1]==blank) {
                blue_result -= 1;
            }
            if (arr[blue_h][blue_result-1]==hole) {
                blue_result -= 1;
            }
            while ((arr[red_h][red_result-1]==blank) && (red_result-1 != blue_result)) {
                red_result -= 1;
            }
            if (arr[red_h][red_result-1]==hole) {
                red_result -= 1;
            }
        }
    }
    else {
        while (arr[red_h][red_result-1]==blank) {
            red_result -= 1;
        }
        if (arr[red_h][red_result-1]==hole) {
            red_result -= 1;
        }
        while (arr[blue_h][blue_result-1]==blank) {
            blue_result -= 1;
        }
        if (arr[blue_h][blue_result-1]==hole) {
            blue_result -= 1;
        }
    }
    pair<int,int> red_coord = make_pair(red_h,red_result);
    pair<int,int> blue_coord = make_pair(blue_h,blue_result);
    pair< pair<int,int>,pair<int,int> > result_state = make_pair(red_coord, blue_coord);
    return result_state;
}

pair< pair<int,int>,pair<int,int> > Right(char arr[][10], int red_h, int red_w, int blue_h, int blue_w) {
    int red_result = red_w;
    int blue_result = blue_w;
    if (red_h == blue_h) {
        if (red_w > blue_w) {
            while (arr[red_h][red_result+1]==blank) {
                red_result += 1;
            }
            if (arr[red_h][red_result+1]==hole) {
                red_result += 1;
            }
            while ((arr[blue_h][blue_result+1]==blank) && (blue_result+1 != red_result)) {
                blue_result += 1;
            }
            if (arr[blue_h][blue_result+1]==hole) {
                blue_result += 1;
            }
        }
        else {
            while (arr[blue_h][blue_result+1]==blank) {
                blue_result += 1;
            }
            if (arr[blue_h][blue_result+1]==hole) {
                blue_result += 1;
            }
            while ((arr[red_h][red_result+1]==blank) && (red_result+1 != blue_result)) {
                red_result += 1;
            }
            if (arr[red_h][red_result+1]==hole) {
                red_result += 1;
            }
        }
    }
    else {
        while (arr[red_h][red_result+1]==blank) {
            red_result += 1;
        }
        if (arr[red_h][red_result+1]==hole) {
            red_result += 1;
        }
        while (arr[blue_h][blue_result+1]==blank) {
            blue_result += 1;
        }
        if (arr[blue_h][blue_result+1]==hole) {
            blue_result += 1;
        }
    }
    pair<int,int> red_coord = make_pair(red_h,red_result);
    pair<int,int> blue_coord = make_pair(blue_h,blue_result);
    pair< pair<int,int>,pair<int,int> > result_state = make_pair(red_coord, blue_coord);
    return result_state;
}

pair< pair<int,int>,pair<int,int> > Up(char arr[][10], int red_h, int red_w, int blue_h, int blue_w) {
    int red_result = red_h;
    int blue_result = blue_h;
    if (red_w == blue_w) {
        if (red_h < blue_h) {
            while (arr[red_result-1][red_w]==blank) {
                red_result -= 1;
            }
            if (arr[red_result-1][red_w]==hole) {
                red_result -= 1;
            }
            while ((arr[blue_result-1][blue_w]==blank) && (blue_result-1 != red_result)) {
                blue_result -= 1;
            }
            if (arr[blue_result-1][blue_w]==hole) {
                blue_result -= 1;
            }
        }
        else {
            while (arr[blue_result-1][blue_w]==blank) {
                blue_result -= 1;
            }
            if (arr[blue_result-1][blue_w]==hole) {
                blue_result -= 1;
            }
            while ((arr[red_result-1][red_w]==blank) && (red_result-1 != blue_result)) {
                red_result -= 1;
            }
            if (arr[red_result-1][red_w]==hole) {
                red_result -= 1;
            }
        }
    }
    else {
        while (arr[red_result-1][red_w]==blank) {
            red_result -= 1;
        }
        if (arr[red_result-1][red_w]==hole) {
            red_result -= 1;
        }
        while (arr[blue_result-1][blue_w]==blank) {
            blue_result -= 1;
        }
        if (arr[blue_result-1][blue_w]==hole) {
            blue_result -= 1;
        }
    }
    pair<int,int> red_coord = make_pair(red_result, red_w);
    pair<int,int> blue_coord = make_pair(blue_result, blue_w);
    pair< pair<int,int>,pair<int,int> > result_state = make_pair(red_coord, blue_coord);
    return result_state;
}

pair< pair<int,int>,pair<int,int> > Down(char arr[][10], int red_h, int red_w, int blue_h, int blue_w) {
    int red_result = red_h;
    int blue_result = blue_h;
    if (red_w == blue_w) {
        if (red_h > blue_h) {
            while (arr[red_result+1][red_w]==blank) {
                red_result += 1;
            }
            if (arr[red_result+1][red_w]==hole) {
                red_result += 1;
            }
            while ((arr[blue_result+1][blue_w]==blank) && (blue_result+1 != red_result)) {
                blue_result += 1;
            }
            if (arr[blue_result+1][blue_w]==hole) {
                blue_result += 1;
            }
        }
        else {
            while (arr[blue_result+1][blue_w]==blank) {
                blue_result += 1;
            }
            if (arr[blue_result+1][blue_w]==hole) {
                blue_result += 1;
            }
            while ((arr[red_result+1][red_w]==blank) && (red_result+1 != blue_result)) {
                red_result += 1;
            }
            if (arr[red_result+1][red_w]==hole) {
                red_result += 1;
            }
        }
    }
    else {
        while (arr[red_result+1][red_w]==blank) {
            red_result += 1;
        }
        if (arr[red_result+1][red_w]==hole) {
            red_result += 1;
        }
        while (arr[blue_result+1][blue_w]==blank) {
            blue_result += 1;
        }
        if (arr[blue_result+1][blue_w]==hole) {
            blue_result += 1;
        }
    }
    pair<int,int> red_coord = make_pair(red_result, red_w);
    pair<int,int> blue_coord = make_pair(blue_result, blue_w);
    pair< pair<int,int>,pair<int,int> > result_state = make_pair(red_coord, blue_coord);
    return result_state;
}


int main() {
    int height, width;
    char board[10][10] = {'#'};
    cin >> height >> width;

    string row;
    for (int i=0; i<height; i++) {
        cin >> row;
        strcpy(board[i],row.c_str());
    }

    pair<int,int> ori_red_coor = make_pair(0,0);
    pair<int,int> ori_blue_coor = make_pair(0,0);
    pair<int,int> goal = make_pair(0,0);
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (board[i][j]==red) {
                ori_red_coor.first = i;
                ori_red_coor.second = j;
                board[i][j] = blank;
            }
            else if (board[i][j]==blue) {
                ori_blue_coor.first = i;
                ori_blue_coor.second = j;
                board[i][j] = blank;
            }
            else if (board[i][j]==hole) {
                goal.first = i;
                goal.second = j;
            }
            else {
                continue;
            }
        }
    }

    //BFS
    queue< pair < pair< pair<int,int>,pair<int,int> >,int > > state_queue;
    list< pair< pair<int,int>,pair<int,int> > > visited;
    pair< pair<int,int>,pair<int,int> > init_coords = make_pair(ori_red_coor,ori_blue_coor);
    pair < pair< pair<int,int>,pair<int,int> >,int > init_state = make_pair(init_coords,0);
    int min_action_num;
    bool reachable;
    visited.push_back(init_coords);
    state_queue.push(init_state);
    while (!state_queue.empty()) {
        pair < pair< pair<int,int>,pair<int,int> >,int > state = state_queue.front();
        pair< pair<int,int>,pair<int,int> > coords = state.first;
        int current_action_num = state.second;
        state_queue.pop();
       
        pair<int,int> red_coor = coords.first;
        pair<int,int> blue_coor = coords.second;
        int red_h = red_coor.first;
        int red_w = red_coor.second;
        int blue_h = blue_coor.first;
        int blue_w = blue_coor.second;

        pair< pair<int,int>,pair<int,int> > left_state = Left(board, red_h, red_w, blue_h, blue_w);
        pair< pair<int,int>,pair<int,int> > right_state = Right(board, red_h, red_w, blue_h, blue_w);
        pair< pair<int,int>,pair<int,int> > down_state = Down(board, red_h, red_w, blue_h, blue_w);
        pair< pair<int,int>,pair<int,int> > up_state = Up(board, red_h, red_w, blue_h, blue_w);
        //left action
        if (!((left_state.first.first==red_h)
            && (left_state.first.second==red_w)
            && (left_state.second.first==blue_h)
            && (left_state.second.second==blue_w))){
            if ((left_state.first.first==goal.first) && (left_state.first.second==goal.second)) {
                if (!((left_state.second.first==goal.first) && (left_state.second.second==goal.second))) {
                    min_action_num = current_action_num+1;
                    reachable = true;
                    break;
                }
                else {
                    reachable = false;
                }
            }
            else {
                if (!((left_state.second.first==goal.first) && (left_state.second.second==goal.second))) {
                    if (find(visited.begin(), visited.end(), left_state)==visited.end()) {
                        visited.push_back(left_state);
                        pair < pair< pair<int,int>,pair<int,int> >,int > new_state = make_pair(left_state,current_action_num+1);
                        state_queue.push(new_state);
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
        else {
            reachable = false;
        }
        //right action
        if (!((right_state.first.first==red_h)
            && (right_state.first.second==red_w)
            && (right_state.second.first==blue_h)
            && (right_state.second.second==blue_w))){
            if ((right_state.first.first==goal.first) && (right_state.first.second==goal.second)) {
                if (!((right_state.second.first==goal.first) && (right_state.second.second==goal.second))) {
                    min_action_num = current_action_num+1;
                    reachable = true;
                    break;
                }
                else {
                    reachable = false;
                }
            }
            else {
                if (!((right_state.second.first==goal.first) && (right_state.second.second==goal.second))) {
                    if (find(visited.begin(), visited.end(), right_state)==visited.end()) {
                        visited.push_back(right_state);
                        pair < pair< pair<int,int>,pair<int,int> >,int > new_state = make_pair(right_state,current_action_num+1);
                        state_queue.push(new_state);
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
        else {
            reachable = false;
        }
        //down action
        if (!((down_state.first.first==red_h)
            && (down_state.first.second==red_w)
            && (down_state.second.first==blue_h)
            && (down_state.second.second==blue_w))){
            if ((down_state.first.first==goal.first) && (down_state.first.second==goal.second)) {
                if (!((down_state.second.first==goal.first) && (down_state.second.second==goal.second))) {
                    min_action_num = current_action_num+1;
                    reachable = true;
                    break;
                }
                else {
                    reachable = false;
                }
            }
            else {
                if (!((down_state.second.first==goal.first) && (down_state.second.second==goal.second))) {
                    if (find(visited.begin(), visited.end(), down_state)==visited.end()) {
                        visited.push_back(down_state);
                        pair < pair< pair<int,int>,pair<int,int> >,int > new_state = make_pair(down_state,current_action_num+1);
                        state_queue.push(new_state);
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
        else {
            reachable = false;
        }
        //up action
        if (!((up_state.first.first==red_h)
            && (up_state.first.second==red_w)
            && (up_state.second.first==blue_h)
            && (up_state.second.second==blue_w))){
            if ((up_state.first.first==goal.first) && (up_state.first.second==goal.second)) {
                if (!((up_state.second.first==goal.first) && (up_state.second.second==goal.second))) {
                    min_action_num = current_action_num+1;
                    reachable = true;
                    break;
                }
                else {
                    reachable = false;
                }
            }
            else {
                if (!((up_state.second.first==goal.first) && (up_state.second.second==goal.second))) {
                    if (find(visited.begin(), visited.end(), up_state)==visited.end()) {
                        visited.push_back(up_state);
                        pair < pair< pair<int,int>,pair<int,int> >,int > new_state = make_pair(up_state,current_action_num+1);
                        state_queue.push(new_state);
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
        else {
            reachable = false;
        }
    }
    if (!reachable) {
        cout << -1 << endl;
    }
    else {
        cout << min_action_num << endl;
    }
}