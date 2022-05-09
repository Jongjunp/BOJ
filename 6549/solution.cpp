#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000;
long long n,h;
long long histogram[MAX] = {0};
long long seg_tree[4*MAX] = {0};
void init(int start, int end, int node) {
    if (start==end) {
        seg_tree[node] = start;
    }
    else {
        int mid = (start+end)/2;
        init(start,mid,2*node);
        init(mid+1,end,2*node+1);
        if (histogram[seg_tree[2*node]]<histogram[seg_tree[2*node+1]]){
            seg_tree[node]=seg_tree[2*node];
        }
        else {
            seg_tree[node]=seg_tree[2*node+1];
        }
    }
}
long long query(int start, int end, int node, int left,  int right) {
    if (left>end || start>right) {
        return -1;
    }
    if (left<=start && end<=right) {
        return seg_tree[node];
    }
    int mid = (start+end)/2;
    long long idx1 = query(start,mid,2*node,left,right);
    long long idx2 = query(mid+1,end,2*node+1,left,right);
    if (idx1==-1) {
        return idx2;
    }
    if (idx2==-1) {
        return idx1;
    }
    if (histogram[idx1]<histogram[idx2]) {
        return idx1;
    }
    else {
        return idx2;
    }
}
long long sum(int start, int end) {
    long long idx = query(0,n-1,1,start,end);
    long long max_area = histogram[idx]*(end-start+1);
    if (start<=idx-1) {
        long long area = sum(start,idx-1);
        if (max_area<area) {
            max_area = area;
        }
    }
    if (idx+1<=end) {
        long long area = sum(idx+1,end);
        if (max_area<area) {
            max_area = area;
        }
    }
    return max_area;
}
int main() {
    while (true) {
        cin >> n;
        if (n!=0) {
            for (int i=0; i<n; i++) {
                cin >> histogram[i];
            }
            init(0,n-1,1);
            cout << sum(0,n-1) << endl;
        }
        else {
            break;
        }
    }
}