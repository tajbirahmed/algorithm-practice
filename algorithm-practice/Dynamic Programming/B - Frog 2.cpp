#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const ll N = 1e5 + 1;
ll n, h[N], k;
ll dp[N];
ll count(ll x) {
	if (x == 1) return 0; 
	if (x <= k) {
		return abs(h[x] - h[1]); 
	}
	if (dp[x] != -1) return dp[x];
	ll ans = 1e9; 
	for (int i = 1; i <= k; i++) {
		ans = min(ans, count(x - i) + abs(h[x] - h[x - i])); 
	}
	return dp[x] = ans; 
}
void solve() {
	cin >> n >> k; 
	for (int i = 1; i <= n; i++) cin >> h[i]; 
	memset(dp, -1, sizeof dp); 
	cout << count(n); 	
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}