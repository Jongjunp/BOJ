#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 4000001;
const int MOD = 1000000007;
ll f[MAX] = {0};

ll pp(ll a, ll p, ll m) {
    if (p==1) return a;
    ll b = pp(a,p/2,m);
    if (p%2==0) {
        return (b*b)%MOD;
    }
    else {
        return (a*((b*b)%MOD))%MOD;
    }
}

int main() {
    ll N,K;
    cin >> N >> K;
    f[0] = f[1] = 1;
    for (int i=2; i<MAX; i++) {
        f[i] = (i*f[i-1])%MOD;
    }
    cout << (f[N]*pp((f[K]*f[N-K])%MOD,MOD-2,MOD))%MOD << endl;
}