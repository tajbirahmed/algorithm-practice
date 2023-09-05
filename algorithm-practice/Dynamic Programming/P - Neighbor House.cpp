#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n; 
vector <vector <ll>> v;
ll dp[21][3];
ll rec(int i, int prev) {
	if (i == v.size()) {
		return 0;
	}
	if (dp[i][prev] != -1) return dp[i][prev];
	ll ans = min(v[i][(prev + 1) % 3] + rec(i + 1, (prev + 1) % 3), 
							 v[i][(prev + 2) % 3] + rec(i + 1, (prev + 2) % 3));
	return dp[i][prev] = ans; 
}
void solve() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v.push_back({a, b, c}); 
	}
	memset(dp, -1, sizeof dp);
	cout << min({rec(0, 0), rec(0, 1), rec(0, 2)}) << '\n'; 
	v.clear();
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T;
	int t = 1; 
	while (T--) { 
		cout << "Case " << (t++) << ": "; 
		solve(); 
	}
}