#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
/*
	given an integer in the range 1e5
	output the number of ways we can represent
	it by any positive integer
	i.e 
		4 = 1 + 1 + 1 + 1
		4 = 1 + 1 + 2
		4 = 1 + 2 + 1
		4 = 2 + 1 + 1
		4 = 1 + 3
		4 = 3 + 1
		4 = 2 + 2
		4 = 4
	the number can be very large so, output it
	with modulo 1e9 + 7; 
*/
const int N = 1e5 + 1, mod = 1e9 + 7;
int ways[N];
int count(int n) {
	if (n == 0) 
		return 1;
	if (ways[n] != -1) 
		return ways[n];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += count(n - i); 
		ans %= mod;
	}
	return ways[n] = ans; 
}
void solve() {
	int n; 
	cin >> n; 
	memset(ways, -1, sizeof ways);
	cout << count(n) << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}