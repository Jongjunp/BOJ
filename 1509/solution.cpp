#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    string input;
    char targ[2500];
    cin >> targ;
    vector<int> stack;
    for(int i=0; i<strlen(targ)-1; i++) {
        char letter = targ[i];
        if (stack.empty()) {
            stack.push_back(letter);
        }
        else {
            char stacked1 = stack.back();
            stack.pop_back();
            char stacked2 = stack.back();
            if (letter==stacked1) {
                
            }
            else if (letter==stacked2) {

            }
            else {

            }
        }
    }
}