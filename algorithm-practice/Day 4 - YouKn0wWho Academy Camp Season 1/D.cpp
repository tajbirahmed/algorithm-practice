#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 23; 
int n, a[N];
ll dp[N][2]; 
ll total;
ll rec(int i, ll sum) {
	if (i == 1) {
		return abs(total - 2 * sum);
	}
	// if (dp)
	return min(rec(i - 1, sum + a[i]), rec(i - 1, sum));
}
void solve() {
	cin >> n; 
	for (int i = 1; i <= n; i++) { cin >> a[i]; total += a[i];} 
	cout << rec(n, 0);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}