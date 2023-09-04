#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
ll mod = 998244353LL;  
void solve() {
	ll n; cin >> n; 
	ll a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}	
	for (int i = 0; i < n; i++) {
		cin >> b[i]; 
	}
	ll m; cin >> m; 
	ll c[m], d[m];
	for (int i = 0; i < m; i++) {
		cin >> c[i]; 
	}	
	for (int i = 0; i < m; i++) {
		cin >> d[i]; 
	}
	map <ll, ll> mp; 
	for (int i = 0; i < n; i++) {
		mp[a[i]] = b[i]; 
	}
	for (int i = 0; i < m; i++) {
		mp[c[i]] = mp[c[i]] - d[i];
	}
	ll res = 1LL; 
	for (auto i : mp) {
		if (i.second < 0) {
			cout << "0\n"; 
			return;
		}
		if (i.second > 0)
			res *= 2LL;
			res %= mod;
	}
	cout << res << '\n';

 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}