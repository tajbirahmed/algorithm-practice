#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
ll a, b, c, d, e, f;
const ll mod = 10000007LL;
const int N = 1e4 + 1;
ll dp[N];
ll fn(ll n) {
	if (n == 0) return a;
  if (n == 1) return b;
  if (n == 2) return c;
  if (n == 3) return d;
  if (n == 4) return e;
  if (n == 5) return f;
  if (dp[n] != -1) return dp[n]; 
  ll ans = 0; 
  for (int i = 1; i <= 6; i++) {
  	ans += fn(n - i); 
  	ans %= mod; 
  }
  return dp[n] = ans;
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	for (int i = 1; i <= T; i++) {
		memset(dp, -1, sizeof dp); 
		ll n;
		cin >> a >> b >> c >> d >> e >> f >> n; 
		cout << "Case "<< i << ": " << fn(n) << '\n';
	} 
}