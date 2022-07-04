#include <iostream>
using namespace std;
const int MAX = 200001;
long long coeff[MAX];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, op, n;
    long long a, b, c, res;
    n = 0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> op;
        if (op==1) {
            cin >> a >> b;
            coeff[n] = (-b)/a;
            n += 1;
        }
        else {
            cin >> c;
            res = 1;
            for (int j=0; j<n; j++) {
                if (coeff[j]<c)
            }
            if (res>0) {
                cout << "+" << endl;
            }
            else if (res<0) {
                cout << "-" << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
    }
}