#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
/*
	thanks to: https://github.com/BUET-IUPC/BUET-IUPC-2023/blob/main/solutions/D.%20Festive%20Shuffling/solution.cpp
*/
bool is_special[501]; 
int in_between[501][501]; 
int dp[501][501][501]; 
string s; 
int rec(int l, int r, int count_ones) {
	if (l > r) return 0;
	if (dp[l][r][count_ones] != -1) return dp[l][r][count_ones]; 
	int ans = 0;
	if (l == r) return 1; 
	if (is_special[l] and is_special[r]) {
		if (count_ones >= 2) {
			ans = max(ans, 2 + rec(l + 1, r - 1, count_ones - 2));
		}
		if (in_between[l][r] - count_ones >= 2) {
			ans = max(ans, 2 + rec(l + 1, r - 1, count_ones)); 
		}
		if (count_ones >= 1) {
			ans = max({ans, rec(l + 1, r, count_ones - 1), rec(l, r - 1, count_ones - 1)}); 
		}
		if (in_between[l][r] - count_ones >= 1) {
			ans = max({ans, rec(l + 1, r, count_ones), rec(l, r - 1, count_ones)});
		}
	} else if (is_special[l]) {
		if (count_ones >= 1) {
			ans = rec(l + 1, r, count_ones - 1);
			ans = max(ans, rec(l, r - 1, count_ones));
			if (s[r - 1] == '1') ans = max(ans, 2 + rec(l + 1, r - 1, count_ones - 1)); 
		}
		if (in_between[l][r] - count_ones >= 1) {
			ans = max(ans, rec(l + 1, r, count_ones));
			ans = max(ans, rec(l, r - 1, count_ones)); 
			if (s[r - 1] == '0') ans = max(ans, 2 + rec(l + 1, r - 1, count_ones));
		}
	} else if (is_special[r]) {
		if (count_ones >= 1) {
			ans = rec(l, r - 1, count_ones - 1); 
			ans = max(ans, rec(l + 1, r, count_ones));
			if (s[l - 1] == '1') ans = max(ans, 2 + rec(l + 1, r - 1, count_ones - 1)); 
		}
		if (in_between[l][r] - count_ones >= 1) {
			ans = max(ans, rec(l, r - 1, count_ones)); 
			ans = max(ans, rec(l + 1, r, count_ones)); 
			if (s[l - 1] == '0') ans = max(ans, 2 + rec(l + 1, r - 1, count_ones));
		}
	} else {
		ans = max(rec(l + 1, r, count_ones), rec(l, r - 1, count_ones));
		if (s[l - 1] == s[r - 1]) ans = max(ans, 2 + rec(l + 1, r - 1, count_ones));
	}
	return	dp[l][r][count_ones] = ans;
}
void solve() {
	cin >> s; 	
	int n = s.size(); 
	int k; cin >> k; 
	for (int i = 1; i <= k; i++) {
		int x;cin >> x; is_special[x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = i; j <= n; j++) {
			cnt += is_special[j]; 
			in_between[i][j] = cnt; 
		}
	}
	memset(dp, -1, sizeof dp);
	int total_ones = 0; 
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1' and is_special[i]) ++total_ones; 
	} 
	cout << rec(1, n, total_ones);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}