#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const int N = 105; 
ll n, W, w[N], v[N]; 
ll knapsack() {
	ll dp[n + 2][W + 1]; 
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n + 1; i++) {
		for (int wt = 0; wt <= W; wt++) {
			if (i == 1 or wt == 0) dp[i][wt] = 0; 
			else if (w[i - 1] <= wt) {
				dp[i][wt] = max(dp[i - 1][wt - w[i - 1]] + v[i - 1], dp[i - 1][wt]); // **visualization problem**
			} 
			else dp[i][wt] = dp[i - 1][wt];
		}
	}
	return dp[n + 1][W];

}
void solve() {
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	cout << knapsack() << '\n'; 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}