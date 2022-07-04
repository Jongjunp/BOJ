#include <iostream>
using namespace std;
const int MAX = 2500;
int coord[MAX][5];

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long S = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if (S<0) {
        return -1; //cw
    }
    else if (S>0) {
        return 1; //ccw
    }
    else {
        return 0;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> coord[i][0] >> coord[i][1] >> coord[i][2] >> coord[i][3] >> coord[i][4];
    }
    
}