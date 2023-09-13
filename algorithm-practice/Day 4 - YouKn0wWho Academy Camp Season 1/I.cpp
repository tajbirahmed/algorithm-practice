#include "bits/stdc++.h"
using namespace std; 
using ll = long long;

ll mul(ll a, ll b, ll mod) { // a * b % mod
	return __int128(a) * b % mod;
}

ll power(ll a, ll b, ll mod) { // a^b % mod
	ll ans = 1 % mod;
	while (b) {
	if (b & 1) ans = mul(ans, a, mod);
		a = mul(a, a, mod);
		b >>= 1;
	}
	return ans;
}
void solve() {
	int n; cin >> n; 
	string s; cin >> s; 
	ll cnt0, cntq, cnt1;
	cnt0 = cntq = cnt1 = 0;
	ll ans = 0;
	ll mod = 1e9 + 7;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1' or s[i] == '?') {
			ll pow = power(2, cntq, mod);
			ans += (pow * cnt0 % mod) % mod;
			// cout << ans << '\n';
			if (cntq) {
				pow = power(2LL, cntq - 1, mod); 
				ans += (cntq * pow);
			}
			ans %= mod;
			// cout << ans << '\n';
		} 
		if (s[i] == '?') cntq++; 
		else if (s[i] == '0') cnt0++; 
		else cnt1++; 
	}
	cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}