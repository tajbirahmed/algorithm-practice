#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const int N = 1e6 + 1;
ll dp[N]; 
ll count(ll n) {
	if (n <= 9) return 1;
	ll x = n; 
	if (dp[x] != -1) return dp[x];
	ll ans = 1e9; 
	while (x) {
		if (x % 10)
			ans = min(ans, 1 + count(n - x % 10));	
		x /= 10; 
	}
	return dp[n] = ans;
} 
void solve() {
	ll n; cin >> n;
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