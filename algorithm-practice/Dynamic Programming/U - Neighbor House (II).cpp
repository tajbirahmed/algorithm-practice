#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e3 + 3; 		
ll a[N]; 
ll dp[N]; 
ll rec(int i, int n) {
	if (i > n) return 0; 
	if (dp[i] != -1) return dp[i];
	ll ans = rec(i + 1, n); 
	ans = max(ans, a[i] + rec(i + 2, n));
	return dp[i] = ans; 
}
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << max(rec(1, n - 1), rec(2, n)) << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	int t = 1;
	while (T--) { 
		cout << "Case " << (t++) << ":";
		solve(); 
	}
}