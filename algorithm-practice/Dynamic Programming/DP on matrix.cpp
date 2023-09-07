#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
/*
	Given a n * m find the smallest 
	cost path path from (1, 1) to (n, m) 
	given that you can only move 1 unit right 
	=or 1 unit down
*/
ll dp[N][M]; 
ll rec(int i, int j) {
	if (i > n or j > m) return 1e12; 
	if (i == n and j == m) return a[n][m]; 
	if (dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = a[i][j] + rec(i + 1, j) + rec(i, j + 1);
}
void solve() {
	
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}