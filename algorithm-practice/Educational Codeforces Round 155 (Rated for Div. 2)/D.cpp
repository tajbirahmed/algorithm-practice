#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n; cin >> n; 
	ll a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		a[i] ^= a[i - 1];
	}
	ll x = 0; 
	for (int i = 1; i <= n; i++) {
		x += a[i];
	}
	ll ans = 0;
	ll mod = 998244353LL;  

	
	for (ll i = 1; i <= n; i++) {
		ans = ans + (i * a[i]) % mod; 
	}
	a[2] ^= a[1]; 
	a[3] ^= a[1];
	ans = ans + 1 * a[2];
	ans += 2 * a[3]; 
	a[3] ^= a[2]; 
	ans += 1 * a[3];
	cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}
/*
	x = a1 + a1 ^ a2 + a1 ^ a2 ^ a3 + a1 ^ a2 ^ a3 ^ a4
	x ^ a1 = a2 + a2 ^ a3 + a2 ^ a3 ^ a4
*/