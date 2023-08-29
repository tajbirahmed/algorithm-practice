#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const int N = 105; 
ll n, W, w[N], v[N], dp[N][(int) 1e5 + 1]; 
ll rec(ll i, ll weight) {
	if (i == n + 1) return 0; \
	if (dp[i][weight] != -1) return dp[i][weight];
	ll ans = rec(i + 1, weight); 
	if (weight + w[i] <= W) ans = max(ans, rec(i + 1, weight + w[i]) + v[i]);
	return dp[i][weight] = ans;
}
void solve() {
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	memset(dp, -1, sizeof dp);
	cout << rec(1, 0) << '\n'; 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}