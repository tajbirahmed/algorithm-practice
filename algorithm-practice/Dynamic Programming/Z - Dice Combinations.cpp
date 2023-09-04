#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const ll N = 1e6 + 1, mod = 1e9 + 7;
ll dp[N]; 
ll count(ll n) {
	if (n == 0) return 1; 
	if (dp[n] != -1) 
		return dp[n]; 
	ll ans = 0;
	for (int i = 1; i <= min(n, 6LL); i++) {
		ans += count(n - i); 
		ans %= mod; 
	}
	return dp[n] = ans; 
} 
void solve() {
	ll n; cin >> n;
	memset(dp, -1, sizeof dp); 
	cout << count(n) << '\n'; 	
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}