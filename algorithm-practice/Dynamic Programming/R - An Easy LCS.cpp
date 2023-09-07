#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
string s, t;  
int dp[101][101]; 
string x[101][101]; 
int lcs(int i, int j) {
	if (i == s.size() or j == t.size()) { 
		x[i][j] = "";
		return 0;
	} 
	if (dp[i][j] != -1) return dp[i][j];
	int ans1 = lcs(i + 1, j), ans2 = lcs(i, j + 1), ans3 = lcs(i + 1, j + 1); 
	int ans; 
	if (s[i] == t[j]) {
		x[i][j] = s[i] + x[i + 1][j + 1]; 
		ans = 1 + ans3; 
	} 	
	else if (ans1 > ans2) {
		x[i][j] = x[i + 1][j]; 
		ans = ans1; 
	} else if (ans1 < ans2) {
		x[i][j] = x[i][j + 1];
		ans = ans2; 
	} else {
		x[i][j] = min(x[i + 1][j], x[i][j + 1]);
		ans = ans1;
	}
	return dp[i][j] = ans; 
}

void solve() {
	cin >> s >> t;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			x[i][j] = "";
		}
	}
	if (lcs(0, 0)) {
		cout << x[0][0] << '\n';
	} else {
		cout << ":(\n";
	}
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