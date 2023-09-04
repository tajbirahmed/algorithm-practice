#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; cin >> n; 
	ll a[n]; 
	ll mn = 1e9;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		mn = min(mn, abs(x));
	}
	cout << mn << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}