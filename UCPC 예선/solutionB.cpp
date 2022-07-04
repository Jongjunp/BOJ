#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 2500;
long long coord[MAX][4] = {0};
long long weight[MAX] = {0};

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

bool iscross(long long sx1, long long sy1, long long ex1, long long ey1, long long sx2, long long sy2, long long ex2, long long ey2) {
    if ((ccw(sx1,sy1,ex1,ey1,sx2,sy2)*ccw(sx1,sy1,ex1,ey1,ex2,ey2)<=0) && (ccw(sx2,sy2,ex2,ey2,sx1,sy1)*ccw(sx2,sy2,ex2,ey2,ex1,ey1)<=0)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int N;
    long long total_weight = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> coord[i][0] >> coord[i][1] >> coord[i][2] >> coord[i][3] >> weight[i];
        total_weight += weight[i];
    }
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (iscross(coord[i][0],coord[i][1],coord[i][2],coord[i][3],coord[j][0],coord[j][1],coord[j][2],coord[j][3])) {
                total_weight += min(weight[i],weight[j]);
            }
        }
    }
    cout << total_weight << endl;
}