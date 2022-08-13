#include <iostream>
#include <algorithm>
using namespace std;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
    int cp = ((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1));
    if (cp>0) {
        return 1;
    }
    else if (cp<0) {
        return -1;
    }
    else {
        return 0;
    }
}

//0: not cross, 1: cross at one point, 2: cross at edge point
int cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    pair <int,int> l1_p1 = make_pair(x1,y1);
    pair <int,int> l1_p2 = make_pair(x2,y2);
    pair <int,int> l2_p1 = make_pair(x3,y3);
    pair <int,int> l2_p2 = make_pair(x4,y4);
    if (ccw(x1,x2,x3,y1,y2,y3)*ccw(x1,x2,x4,y1,y2,y4)<=0
        && ccw(x3,x4,x1,y3,y4,y1)*ccw(x3,x4,x2,y3,y4,y2)<=0) {
        if (ccw(x1,x2,x3,y1,y2,y3)==0 && ccw(x1,x2,x4,y1,y2,y4)==0) {
            if ((min(l1_p1,l1_p2)>max(l2_p1, l2_p2) || max(l1_p1,l1_p2)<min(l2_p1,l2_p2))) {
                return 0;
            }
            else if ((min(l1_p1,l1_p2)<max(l2_p1,l2_p2) && max(l1_p1,l1_p2)>min(l2_p1,l2_p2))) {
                return 2;
            }
            else {
                return 1;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int rect_cross(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int res1 = cross(x1,y1,x2,y2,xmin,ymax,xmin,ymin);
    int res2 = cross(x1,y1,x2,y2,xmin,ymin,xmax,ymin);
    int res3 = cross(x1,y1,x2,y2,xmax,ymin,xmax,ymax);
    int res4 = cross(x1,y1,x2,y2,xmax,ymax,xmin,ymax);
    if (res1==2 || res2==2 || res3==2 || res4==2) {
        return 4;
    }
    else {
        int num_cross = res1+res2+res3+res4;
        if (num_cross==0) {
            return 0;
        }
        else if (num_cross==1) {
            return 1;
        }
        else if (num_cross==2) {
            if (ccw(x1,x2,xmin,y1,y2,ymax)==0 || ccw(x1,x2,xmin,y1,y2,ymin)==0 || ccw(x1,x2,xmax,y1,y2,ymin)==0 || ccw(x1,x2,xmax,y1,y2,ymax)==0) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else {
            return 2;
        }
    }
}

int main() {
    int T, xmin, ymin, xmax, ymax, x1, y1, x2, y2;
    scanf("%d",&T);
    for (int i=0; i<T; i++) {
        scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", rect_cross(x1,y1,x2,y2,xmin,ymin,xmax,ymax));
    }
}