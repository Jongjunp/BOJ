#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int arr_size;
    cin >> arr_size;
    vector<int> A,B,C,D;
    for (int i=0; i<arr_size; i++){
        int a,b,c,d;
        cin << a << b << c << d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    if (A)
}