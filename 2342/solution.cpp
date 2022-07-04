#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;
const int REPEAT = 1;
const int INIT = 2;
const int ADJACENT = 3;
const int REVERSE = 4;
const int MAX = 1000000;
int main() {
    unordered_map<int,queue< pair< pair<int,int>,int > > > dp;
    int command_arr[100000] = {0};
    pair<int,int> init_state = make_pair(0,0);
    pair< pair<int,int>,int > init_state_cost = make_pair(init_state,0);
    queue< pair< pair<int,int>,int > > init_queue;
    init_queue.push(init_state_cost);
    dp.insert(make_pair(0,init_queue));
    int input = MAX;
    int index = 0;
    while (input!=0) {
        cin >> input;
        command_arr[index] = input;
        index += 1;
    }
    for (int idx=0; idx<index-1; idx++) {
        int command = command_arr[idx];
        queue< pair< pair<int,int>,int > > prev_states = dp[idx];
        queue< pair< pair<int,int>,int > > next_states;
        dp.insert(make_pair(idx+1,next_states));
        while (!prev_states.empty()){
            int left = prev_states.front().first.first;
            int right = prev_states.front().first.second;
            int cost = prev_states.front().second;
            prev_states.pop();
            if (left==0) {
                pair<int,int> next_state = make_pair(command,right);
                pair< pair<int,int>,int > state_cost = make_pair(next_state,cost+INIT);
                dp[idx+1].push(state_cost);
            }
            else if (right==0) {
                pair<int,int> next_state = make_pair(left,command);
                pair< pair<int,int>,int > state_cost = make_pair(next_state,cost+INIT);
                dp[idx+1].push(state_cost);
            }
            else if (command==left || command==right) {
                pair<int,int> next_state = make_pair(left,right);
                pair< pair<int,int>,int > state_cost = make_pair(next_state,cost+REPEAT);
                dp[idx+1].push(state_cost);
            }
            else if (abs(command%4-left%4) == abs(command%4-right%4)) {
                pair<int,int> next_state1 = make_pair(command,right);
                pair< pair<int,int>,int > state_cost1 = make_pair(next_state1,cost+ADJACENT);
                dp[idx+1].push(state_cost1);
                pair<int,int> next_state2 = make_pair(left,command);
                pair< pair<int,int>,int > state_cost2 = make_pair(next_state2,cost+ADJACENT);
                dp[idx+1].push(state_cost2);
            }
            else if (abs(command%4-left%4) < abs(command%4-right%4)) {
                pair<int,int> next_state1 = make_pair(command,right);
                pair< pair<int,int>,int > state_cost1 = make_pair(next_state1,cost+ADJACENT);
                dp[idx+1].push(state_cost1);
                pair<int,int> next_state2 = make_pair(left,command);
                pair< pair<int,int>,int > state_cost2 = make_pair(next_state2,cost+REVERSE);
                dp[idx+1].push(state_cost2);
            }
            else if (abs(command%4-left%4) > abs(command%4-right%4)) {
                pair<int,int> next_state1 = make_pair(command,right);
                pair< pair<int,int>,int > state_cost1 = make_pair(next_state1,cost+REVERSE);
                dp[idx+1].push(state_cost1);
                pair<int,int> next_state2 = make_pair(left,command);
                pair< pair<int,int>,int > state_cost2 = make_pair(next_state2,cost+ADJACENT);
                dp[idx+1].push(state_cost2);
            }
        }
    }
    int min_cost = MAX;
    queue< pair< pair<int,int>,int > > final_result = dp[index-1];
    while(!final_result.empty()) {
        int cost = final_result.front().second;
        if (cost < min_cost) {
            min_cost = cost;
        }
        final_result.pop();
    }
    cout << min_cost << endl;
}