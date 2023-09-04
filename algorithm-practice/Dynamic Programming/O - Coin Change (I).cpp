#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n, k; 
const int N = 52;
int a[N], c[N];
ll mod = 1e9 + 7LL;
ll dp[N][1001];   
ll rec(int i, ll curr) {
	if (i == n + 1) {
		if (curr == k) return 1; 
		else return 0;
	} 
	if (curr > k) return 0; 
	if (dp[i][curr] != -1) return dp[i][curr]; 
	ll ans = 0; 
 	for (int j = 0; j <= c[i]; j++) {
		ans += rec(i + 1, curr + a[i] * j); 
		ans %= mod; 
	}
	return dp[i][curr] = ans; 
}
void solve() {
	cin >> n >> k; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i]; 
	}
	memset(dp, -1, sizeof dp); 
	cout << rec(1, 0) << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	int t = 1;
	while (T--){
		cout << "Case " << (t++) << ": ";  
		solve(); 
	}
}