#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

const char virus = '2';
const char block = '1';
const char blank = '0';

int main() {
    int height, width;
    char board[8][8] = {'0'};
    cin >> height >> width;

    string row;
    for (int i=0; i<height; i++) {
        scanf("%s",board[i]);
    }
    int total_space = 0;
    bool visited[8][8] = {false};
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (board[i][j]!=block){
                total_space += 1;
            }
            else{
                visited[i][j] = true;
            }
        }
    }
    //BFS and brute force
    for 
    queue< pair<int,int> >
}