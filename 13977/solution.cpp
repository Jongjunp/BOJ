#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int MAX = 4000001;
typedef long long ll;
ll f[MAX];

ll pp(ll a, ll p, ll M)
{
    if(p==1) return a;
    ll b = pp(a,p/2,M);
    if(p%2==0){
        return (b*b)%M;
    }else{
        return (((b*b)%M)*a)%M;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll M,N,K;
    cin >> M;
    f[0]=f[1]=1;
    for(int i=2;i<MAX;i++) {
        f[i]=(i*f[i-1])%MOD;
    }
    for (int i=0; i<M; i++) {
        cin >> N >> K;
        cout << (f[N]*pp((f[K]*f[N-K])%MOD,MOD-2,MOD))%MOD << "\n";
    }
}