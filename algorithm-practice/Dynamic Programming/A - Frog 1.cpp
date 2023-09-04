#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const ll N = 1e5 + 1;
ll n, h[N];
ll dp[N];
ll count(ll x) {
	if (x == 1) return 0;
	if (x == 2) return abs(h[2] - h[1]);
	if (dp[x] != -1) return dp[x]; 
	ll ans = count(x - 1) + abs(h[x] - h[x - 1]); 
	ans = min(ans, count(x - 2) + abs(h[x] - h[x - 2]));
	return dp[x] = ans; 
}
void solve() {
	cin >> n; 
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