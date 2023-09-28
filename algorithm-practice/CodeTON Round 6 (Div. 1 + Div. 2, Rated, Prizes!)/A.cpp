#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n, k, x; 
	cin >> n >> k >> x;
	if (k > n or x + 1 < k) cout << "-1\n"; 
	else {
		ll sum = 0; 
		n--;
		for (int i = 1; i < k; i++) {
			sum += i; 
			n--; 
		}
		if (x == k) {
			while (n > 0) sum += (x  - 1), n--; 
		} else {
			while (n > 0) sum += x, n--; 
		}
		cout << sum << '\n';
	}
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}