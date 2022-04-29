#include <iostream>
using namespace std;
typedef long long ll;
ll cnt[1000];
ll arr[1000001];

int main(){
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		arr[i] += arr[i-1];
		arr[i] %= m;
		cnt[arr[i]]++;
	}

	ll ans = cnt[0];
	for(int i=0; i<m; i++){
		ll now = cnt[i];
		ans += now * (now - 1) / 2;
	}
	cout << ans << endl;
}