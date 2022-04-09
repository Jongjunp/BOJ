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
    int command_arr[100000] = {0};
    int dp[100001][5][5] = {MAX};
    int input = MAX;
    int index = 0;
    while (input!=0) {
        cin >> input;
        command_arr[index] = input;
        index += 1;
    }
    for (int idx=0; idx<index-1; idx++) {
        int command = command_arr[idx];
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                int left = i;
                int right = j;
                if (idx==0) {
                    
                }
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