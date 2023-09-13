#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const ll MX = LLONG_MAX;
void solve() {
	int n, k, a, b;
	cin >> n >> k >> a >> b; 
	ll x[n], y[n]; 
	for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i]; 
	}	
	a--; b--;
	ll mn1 = MX;
	for (int i = 0; i < k; i++) {
		mn1 = min(mn1, abs(x[a] - x[i]) + abs(y[a] - y[i])); 
	}
	ll mn2 = MX; 
	for (int i = 0; i < k; i++) {
		mn2 = min(mn2, abs(x[b] - x[i]) + abs(y[b] - y[i])); 
	}
	ll mn = abs(x[a] - x[b]) + abs(y[a] - y[b]); 
	// cout << mn1 << ' ' << mn2 << ' ' << mn << '\n';
	if (k) 
		cout << min({mn1 + mn2, mn}) << '\n';
	else cout << mn << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}