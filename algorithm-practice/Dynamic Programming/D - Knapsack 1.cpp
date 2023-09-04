#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n, W; 
const int N = 101, WW = 1e5 + 1;
vector <ll> v, w;
ll dp[N][WW]; 
ll rec(int i, ll weight) {
	if (i == n) 
		return 0; 
	if (dp[i][weight] != -1) return dp[i][weight]; 
	ll ans = rec(i + 1, weight); 
	if (w[i] + weight <= W) 
		ans = max(ans, v[i] + rec(i + 1, w[i] + weight));
	return dp[i][weight] = ans; 
}
void solve() {
	cin >> n >> W;
	for (int i = 1; i <= n; i++) {
		ll x, y;
		cin >> x >> y;
		w.push_back(x);
		v.push_back(y);
	}
	memset(dp, -1, sizeof dp);
	cout << rec(0, 0LL);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}