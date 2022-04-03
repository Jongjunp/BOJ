#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (1) {
        int hole_width, num_lego;
        vector<int> length_arr;
        if (!(cin >> hole_width)) {
            break;
        }
        cin >> num_lego;
        hole_width = hole_width*10000000;
        int lego_length;
        for (int i=1; i<=num_lego; i++) {
            cin >> lego_length;
            length_arr.push_back(lego_length);
        }
        sort(length_arr.begin(), length_arr.end());
        int left = 0;
        int right = length_arr.size()-1;
        bool flag = false;
        while (left < right) {
            if (length_arr[left] + length_arr[right] > hole_width){
                right -= 1;
            }
            else if (length_arr[left] + length_arr[right] < hole_width){
                left += 1;
            }
            else {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "yes " << length_arr[left] << " " << length_arr[right] << endl;
        }
        else {
            cout << "danger" << endl;
        }
    }
    return 0;
}