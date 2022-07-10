#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int MAX = 10000001;
typedef long long ll;

ll powmat[32] = {0};
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

ll twoPower(int x) {
    for (int i=0; i<=31; i++) {
        if (i==0) {
            powmat[i]=1;
        }
        else if (i==1) {
            powmat[i]=2;
        }
        else {
            powmat[i] = (powmat[i-1]*powmat[i-1])%MOD;
        }
    }
    int cnt = 1;
    int temp = x;
    ll answer = 1;
    while (temp!=0) {
        if (temp%2==1) {
            answer = (answer*powmat[cnt])%MOD;
        }
        temp /= 2;
        cnt += 1;
    }
    return answer;
}

int main() {
    int N,K,n;
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> n;
    }
    f[0]=f[1]=1;
    for(int i=2;i<MAX;i++) {
        f[i]=(i*f[i-1])%MOD;
    }
    ll temp1 = (f[N]*pp((f[K]*f[N-K])%MOD,MOD-2,MOD))%MOD;
    ll temp2 = twoPower(K-1);
    ll ans = (temp1*temp2)%MOD;
    cout << ans << endl;
}