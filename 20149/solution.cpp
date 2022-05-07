#include <iostream>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;
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
pair<double, double> crosscoor(ll x1, ll x2, ll x3, ll x4, ll y1, ll y2, ll y3, ll y4) {
    double xd1 = static_cast<double>(x1);
    double xd2 = static_cast<double>(x2);
    double xd3 = static_cast<double>(x3);
    double xd4 = static_cast<double>(x4);
    double yd1 = static_cast<double>(y1);
    double yd2 = static_cast<double>(y2);
    double yd3 = static_cast<double>(y3);
    double yd4 = static_cast<double>(y4);
    pair <ll,ll> l1_p1 = make_pair(x1,y1);
    pair <ll,ll> l1_p2 = make_pair(x2,y2);
    pair <ll,ll> l2_p1 = make_pair(x3,y3);
    pair <ll,ll> l2_p2 = make_pair(x4,y4);
    if ((yd2-yd1)*(xd4-xd3)-(yd4-yd3)*(xd2-xd1)==0) {
        if (min(l1_p1,l1_p2)==max(l2_p1, l2_p2)) {
            return make_pair(static_cast<double>(min(l1_p1,l1_p2).first),static_cast<double>(min(l1_p1,l1_p2).second));
        }
        else if (max(l1_p1,l1_p2)==min(l2_p1,l2_p2)) {
            return make_pair(static_cast<double>(max(l1_p1,l1_p2).first),static_cast<double>(max(l1_p1,l1_p2).second));
        }
        else {
            return make_pair(-1,-1);
        }
    }
    else {
        double cross_x = (((yd3-yd1)*(xd2-xd1)*(xd4-xd3))-(xd3*(yd4-yd3)*(xd2-xd1))+(xd1*(yd2-yd1)*(xd4-xd3)))/((yd2-yd1)*(xd4-xd3)-(yd4-yd3)*(xd2-xd1));
        double cross_y;
        if (xd2==xd1) {
            cross_y = ((yd4-yd3)/(xd4-xd3))*(cross_x-xd3)+yd3;
        }
        else {
            cross_y = ((yd2-yd1)/(xd2-xd1))*(cross_x-xd1)+yd1;
        }
        return make_pair(cross_x, cross_y);
    }
}
int main() {
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    pair <ll,ll> l1_p1 = make_pair(x1,y1);
    pair <ll,ll> l1_p2 = make_pair(x2,y2);
    pair <ll,ll> l2_p1 = make_pair(x3,y3);
    pair <ll,ll> l2_p2 = make_pair(x4,y4);
    if (poscheck(x1,x2,x3,y1,y2,y3)*poscheck(x1,x2,x4,y1,y2,y4)<=0
        && poscheck(x3,x4,x1,y3,y4,y1)*poscheck(x3,x4,x2,y3,y4,y2)<=0) {
        if (poscheck(x1,x2,x3,y1,y2,y3)==0 && poscheck(x1,x2,x4,y1,y2,y4)==0) {
            if ((min(l1_p1,l1_p2)>max(l2_p1, l2_p2) || max(l1_p1,l1_p2)<min(l2_p1,l2_p2))) {
                cout << 0 << endl;
            }
            else if ((min(l1_p1,l1_p2)<max(l2_p1,l2_p2) && max(l1_p1,l1_p2)>min(l2_p1,l2_p2))) {
                cout << 1 << endl;
            }
            else {
                cout << 1 << endl;
                pair<double, double> answer = crosscoor(x1,x2,x3,x4,y1,y2,y3,y4);
                printf("%.10f %.10f\n",answer.first, answer.second);
            }
        }
        else {
            cout << 1 << endl;
            pair<double, double> answer = crosscoor(x1,x2,x3,x4,y1,y2,y3,y4);
            printf("%.10f %.10f\n",answer.first, answer.second);
        }
    }
    else {
        cout << 0 << endl;
    }
}