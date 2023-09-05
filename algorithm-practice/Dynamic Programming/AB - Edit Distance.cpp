#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
string s, t;  
ll dp[5001][5001];
ll rec(int i, int j) {
	if (i == s.size() and j == t.size()) return 0; 
	if (i == s.size()) return t.size() - j; 
	if (j == t.size()) return s.size() - i;
	if (dp[i][j] != -1) return dp[i][j];
	ll ans = min({1 + rec(i + 1, j + 1), 1 + rec(i + 1, j), 1 + rec(i, j + 1)}); 
	if (s[i] == t[j]) {
		ans = min(ans, rec(i + 1, j + 1)); 
	}
	return dp[i][j] = ans;
}
void solve() {
		memset(dp, -1, sizeof dp);
		cin >> s >> t;
		cout << rec(0, 0);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}