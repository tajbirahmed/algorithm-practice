#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e5 + 1;
vector <vector <ll>> v; 
ll dp[N][3]; 
ll count(int i, int prev_i) {
	if (i == v.size()) return 0;
	if (dp[i][prev_i] != -1) return dp[i][prev_i];
	ll mx; 
	if (prev_i == 0) {
		mx = max(v[i][1] + count(i + 1, 1), v[i][2] + count(i + 1, 2));
	} else if (prev_i == 1) {
		mx = max(v[i][0] + count(i + 1, 0), v[i][2] + count(i + 1, 2));
	} else 
		mx = max(v[i][1] + count(i + 1, 1), v[i][0] + count(i + 1, 0));
	return dp[i][prev_i] = mx;
}
void solve() {
	int n; cin >> n; 
	for (int i = 1; i <= n; i++) {
		ll a, b, c; cin >> a >> b >> c; 
		v.push_back({a, b, c});
	}
	memset(dp, -1, sizeof dp);
	cout << max({count(0, 0), count(0, 1), count(0, 2)});
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}