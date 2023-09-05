#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n, W; 
const int N = 101, V = 1e5 + 10;
vector <ll> v, w;
ll dp[N][V]; 
ll rec(int i, ll val) {
	if (i == -1) {
		if (val) return 1e12; 
		return 0;
	}
	if (dp[i][val] != -1) return dp[i][val];
	ll ans = rec(i - 1, val); 
	if (val - v[i] >= 0) 
		ans = min(ans, rec(i - 1, val - v[i]) + w[i]);
	return dp[i][val] = ans;
}
void solve() {
	cin >> n >> W;
	ll tot_value = 0LL; 
	for (int i = 1; i <= n; i++) {
		ll x, y;
		cin >> x >> y;
		w.push_back(x);
		v.push_back(y);
		tot_value += y;
	}
	memset(dp, -1, sizeof dp);
	for (ll val = tot_value; val >= 0; val--) {
		if (rec(n, val) <= W) {
			cout << val << '\n'; 
			return; 
		}
	}
	// cout << rec(0, 0LL);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}