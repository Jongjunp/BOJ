#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 10001;
long long coords[MAX][4] = {0};
int parent[MAX] = {0};
int group_size[MAX] = {0};

int find_op(int x) {
    if (x==parent[x]) return x;
    parent[x] = find_op(parent[x]);
    return parent[x];
}

void union_op(int x, int y) {
    int parent_x = find_op(x);
    int parent_y = find_op(y);
    if (parent_x==parent_y) return;
    if (group_size[parent_x]>group_size[parent_y]) {
        parent[parent_y] = parent_x;
        group_size[parent_x] += group_size[parent_y];
        group_size[parent_y] = 0;
    }
    else {
        parent[parent_x] = parent_y;
        group_size[parent_y] += group_size[parent_x];
        group_size[parent_x] = 0;
    }
}

int ccw(long long x1, long long x2, long long x3, long long y1, long long y2, long long y3) {
    long long val = ((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1));
    if (val>0) {
        return 1;
    }
    else if (val<0) {
        return -1;
    }
    else {
        return 0;
    }
}

bool cross(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4) {
    if (ccw(x1,x2,x3,y1,y2,y3)==0 && ccw(x1,x2,x4,y1,y2,y4)==0) {
        if ((min(x1,x2)<=x3 && max(x1,x2)>=x3) ||
        (min(x1,x2)<=x4 && max(x1,x2)>=x4)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main() {
    for (int i=0; i<MAX; i++) {
        parent[i] = i;
        group_size[i] = 1;
    }
    int N;
    long long x1, y1, x2, y2;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        float x1, y1, x2, y2;
        scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
        coords[i][0] = (long long)(x1*100);
        coords[i][1] = (long long)(y1*100);
        coords[i][2] = (long long)(x2*100);
        coords[i][3] = (long long)(y2*100);
        for (int j=0; j<i; j++) {
            if (cross(coords[i][0],coords[i][1],coords[i][2],coords[i][3],coords[j][0],coords[j][1],coords[j][2],coords[j][3])) {
                union_op(i,j);
            }
        }
    }
    int answer = 0;
    for (int i=0; i<N; i++) {
        if (parent[i]==i) {
            answer++;
        }
    }
    printf("%d\n", answer);
}