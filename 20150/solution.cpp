#include <iostream>
#include <utility>
#include <algorithm>
typedef long long ll;
const int MAX = 200000;
using namespace std;
ll arr[MAX][4] = {0};
int poscheck(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
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
int main() {
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    pair <ll,ll> l1_p1 = make_pair(x1,y1);
    pair <ll,ll> l1_p2 = make_pair(x2,y2);
    pair <ll,ll> l2_p1 = make_pair(x3,y3);
    pair <ll,ll> l2_p2 = make_pair(x4,y4);
    if (poscheck(x1,x2,x3,y1,y2,y3)*poscheck(x1,x2,x4,y1,y2,y4)<=0
        && poscheck(x3,x4,x1,y3,y4,y1)*poscheck(x3,x4,x2,y3,y4,y2)<=0) {
        if (poscheck(x1,x2,x3,y1,y2,y3)==0 && poscheck(x1,x2,x4,y1,y2,y4)==0
            && (min(l1_p1,l1_p2)>max(l2_p1, l2_p2) || max(l1_p1,l1_p2)<min(l2_p1,l2_p2))){
            cout << 0 << endl; 
        }
        else {
            cout << 1 << endl;
        }
    }
    else {
        cout << 0 << endl;
    }
}