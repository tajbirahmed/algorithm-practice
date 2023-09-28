#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1010; 
ll dp[N][N]; 
bool a[N][N];
int n, m;  
const ll mod = 1e9 + 7;
int grid (int i, int j) {
	if (i == n - 1 and j == m - 1) {
		return 1; 
	}
	if (i > n or j > m) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	ll ans = a[i + 1][j] ? grid(i + 1, j) : 0; 
	ans %= mod;
	ans += a[i][j + 1] ? grid(i, j + 1) : 0;  
	ans %= mod; 
	return dp[i][j] = ans; 
}
void solve() {
	cin >> n >> m;
	memset (dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c; 
			if (c == '.') a[i][j] = 1; 
			else a[i][j] = 0;
		}
	}
	cout << grid(0, 0) << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}