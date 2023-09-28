#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 2e5 + 10; 
int dp[N];
vector <int> adj[N]; 
int dfs(int u) {
	if (dp[u] != -1) return dp[u]; 
	int ans = 0; 
	for (auto v : adj[u]) {
		ans = max(ans, 1 + dfs(v)); 
	}
	return dp[u] = ans;
}
void solve() {
	int n, m; 
	cin >> n >> m; 
	while (m--) {
		int u, v; cin >> u >> v; 
		adj[u].push_back(v); 
	}
	int ans = 0; 
	memset (dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dfs(i)); 
	}
	cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}