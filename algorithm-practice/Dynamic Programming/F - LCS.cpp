#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
string s, t;
int dp[3002][3002];
int lcs(int i, int j) {
	if (i == s.size() or j == t.size()) {
		return 0; 
	}
	if (dp[i][j] != -1) return dp[i][j];
	int ans = max(lcs(i + 1, j), lcs(i, j + 1));
	if (s[i] == t[j]) 
		ans = max(ans, 1 + lcs(i + 1, j + 1)); 
	return dp[i][j] = ans;
}
void print (int i, int j) {
	if (i == s.size() or j == t.size()) return;
	if (s[i] == t[j]) {
		cout << s[i];
		print (i + 1, j + 1); 
		return;
	} 
	int x = lcs(i + 1, j); 
	int y = lcs(i, j + 1); 
	if (x > y) {
		print (i + 1, j); 
	} else {
		print (i, j + 1); 
	}

}
void solve() {
	memset (dp, -1, sizeof dp);
	cin >> s >> t; 
	print(0, 0); 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}