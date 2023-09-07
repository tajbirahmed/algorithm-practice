#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
string s, t;
int dp[3001][3001]; 
int lcs(int i, int j) {
	if (i == s.size() or j == t.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j]; 
	ll ans = max({lcs(i + 1, j), lcs(i, j + 1), (s[i] == t[j]) * (1 + lcs(i + 1, j + 1))}); 
	return dp[i][j] = ans; 
}	
void print(int i, int j) {
	if (i == s.size() or j == t.size()) return; 
	if (s[i] == t[j]) {
		cout << s[i]; 
		print(i + 1, j + 1); 
		return; 
	}
	int x = lcs(i, j + 1); 
	int y = lcs(i + 1, j); 
	if (x > y) {
		print (i, j + 1); 
	} else {
		print(i + 1, j);
	}
}
void solve() {
	cin >> s >> t;
	memset(dp, -1, sizeof dp); 
	// cout << lcs(0, 0) << "\n"; 
	print (0, 0);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}