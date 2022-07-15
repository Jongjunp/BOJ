#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int G;
    cin >> G;
    int left = 1;
    int right = 1;
    int cnt = 0;
    while (true) {
        if (right-left==1 && (right*right)-(left*left)>G) {
            break;
        }
        if ((right*right)-(left*left)<G) {
            right += 1;
            continue;
        }
        if ((right*right)-(left*left)==G) {
            cout << right << endl;
            cnt += 1;
        }
        left += 1;
    }
    if (cnt==0) {
        cout << -1 << endl;
    }
}