#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
string s, t;  
int dp[1001][1001]; 
int rec(int i, int j) {
	if (i > j) return 0; 
	if (i == j) return 1;
	if (dp[i][j] != -1) return dp[i][j]; 
	int ans = max(rec(i + 1, j), rec(i, j - 1)); 
	if (s[i] == s[j]) ans = max(ans, 2 + rec(i + 1, j - 1)); 
	return dp[i][j] = ans;
}
void solve() {
	getline(cin, s);
	memset(dp, -1, sizeof dp);
	cout << rec(0, s.size() - 1) << '\n'; 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	cin.ignore();
	while (T--) solve(); 
}