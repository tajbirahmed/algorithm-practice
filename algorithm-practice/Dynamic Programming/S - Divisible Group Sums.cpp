#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n; 
const int N = 202; 
ll a[N];
ll dp[N][11][21]; 
int d, m;
ll rec(int i, int cnt, int sum) {
	if (i == n + 1) {
		if (cnt == m and sum == 0) return 1; 
		else return 0;
	}
	if (dp[i][cnt][sum] != -1) return dp[i][cnt][sum];
	ll ans = rec(i + 1, cnt, sum); 
	ans += rec(i + 1, cnt + 1, (((sum + a[i]) % d + d ) % d));
	return dp[i][cnt][sum] = ans;
}

void solve() {
	int q; 
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (q--) {
		cin >> d >> m; 
		memset(dp, -1, sizeof dp);
		cout << rec(1, 0, 0) << '\n';
	}
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	int t = 1;
	while (T--) { 
		cout << "Case " << (t++) << ":\n";
		solve(); 
	}
}