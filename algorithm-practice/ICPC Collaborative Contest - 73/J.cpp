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
	int m; 
	cin >> m; 
	map <ll, ll> mp; 
	vec <ll> a(m);  
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		mp[a[i]]++; 
	}	
	ll N = 1; 
	ll mod = 1e9 + 7; 
	for (int i = 0; i < m; i++) {
		N = mul(N, a[i], mod); 
	}
	ll 
} 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}