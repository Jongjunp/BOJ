#include <iostream>
#include <utility>
#include <algorithm>
const int MAX = 3001;
int coords[MAX][4] = {0};
int parent[MAX] = {0};
int group_size[MAX] = {0};
using namespace std;

int poscheck(int x1, int x2, int x3, int y1, int y2, int y3) {
    if ((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1)>0) {
        return 1;
    }
    else if ((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1)<0) {
        return -1;
    }
    else {
        return 0;
    }
}

bool crosscheck(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    pair <int, int> l1_p1 = make_pair(x1,y1);
    pair <int,int> l1_p2 = make_pair(x2,y2);
    pair <int,int> l2_p1 = make_pair(x3,y3);
    pair <int,int> l2_p2 = make_pair(x4,y4);
    if (poscheck(x1,x2,x3,y1,y2,y3)*poscheck(x1,x2,x4,y1,y2,y4)<=0
        && poscheck(x3,x4,x1,y3,y4,y1)*poscheck(x3,x4,x2,y3,y4,y2)<=0) {
        if (poscheck(x1,x2,x3,y1,y2,y3)==0 && poscheck(x1,x2,x4,y1,y2,y4)==0 && (min(l1_p1,l1_p2)>max(l2_p1, l2_p2) || max(l1_p1,l1_p2)<min(l2_p1,l2_p2))) {
                return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int find(int x) {
    if (x==parent[x]) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void union_op(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return;
    if (group_size[x]>group_size[y]) {
        parent[y] = x;
        group_size[x] += group_size[y];
        group_size[y] = 0;
    }
    else {
        parent[x] = y;
        group_size[y] += group_size[x];
        group_size[x] = 0;
    }
}

int main() {
    for (int i=0; i<MAX; i++) {
        parent[i] = i;
        group_size[i] = 1;
    }
    int N;
    int num_group = 0;
    int max_size = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> coords[i][0] >> coords[i][1] >> coords[i][2] >> coords[i][3];
        if (i!=0) {
            for (int j=0; j<i; j++) {
                if (crosscheck(coords[j][0],coords[j][1],coords[j][2],coords[j][3],coords[i][0],coords[i][1],coords[i][2],coords[i][3])) {
                    union_op(i,j);
                }
            }
        }
    }
    for (int i=0; i<N; i++) {
        if (group_size[i]!=0) {
            num_group += 1;
        }
        if (group_size[i]>max_size) {
            max_size = group_size[i];
        }
    }
    cout << num_group << endl;
    cout << max_size << endl;
}