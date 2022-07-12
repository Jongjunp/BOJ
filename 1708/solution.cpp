#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100001;

int ccw()

struct coord {
    int x,y;
    coord(int x, int y) : x(x), y(y) {}
};

struct cmp {
    bool operator()(coord c1, coord c2) {
        
    }
}

priority_queue< coord, vector<coord>, cmp> coords;
vector< coord > stack;
coord temp[MAX];
int main() {
    int N,x,y,cnt;
    cnt = 0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        coords.push(make_pair(x,y));
    }
    if (cnt==0 || cnt==1) {
        stack.push_back(make_pair(coords.top().first,coords.top().second));
        coords.pop();
    }
    int new_x = coords.top().first;
    int new_y = coords.top().second;
    int second_x = stack.back().first;
    int second_y = stack.back().second;
    stack.pop_back();
    int first_x = stack.back().first;
    int first_y = stack.back().second;
    stack.pop_back();
}