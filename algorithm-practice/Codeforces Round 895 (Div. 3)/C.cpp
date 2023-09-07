#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
vector <int> primes; 
const int N = 1e7 + 1;
vector <bool> p(N);
void pre () {
	p[0] = p[1] = 0;
	for (int i = 2; i < N; i++) {
		p[i] = 1; 
	}
	for (int i = 2; i < N; i++) {
		if (p[i]){
			for (int j = 2 * i; j < N; j += i) {
				p[j] = false;
			}
		}
	}
	ll mx = -1; 
	for (ll i = 2; i < N; i++) {
		if (p[i]) {
			if (i * i < N) mx = max(mx, i * i);
		}
	}
	cout << mx << '\n';
}
void solve() {
	ll l, r; 
	cin >> l >> r; 
	// if (!(l & 1) or !(r & 1)) {
	// 	if (!(l & 1)) {
	// 		cout << (l / 2) << ' ' << (l / 2) << '\n';
	// 	} else 
	// 		cout << (r / 2) << ' ' << (r / 2) << '\n';
	// } else {
	// 	if (r - l > 2) {
	// 		ll x = l + 1;
	// 		cout << (x / 2) << ' ' << (x / 2) << '\n';
	// 	} else cout << "A\n";
	// }
	ll q = -1; 
	// cout << l << ' ' << r << "->";
	for (int i = (l == 1) ? 2 : l; i <= r; i++) {
		if (!p[i]) {
			q = i; 
			break; 
		}
	} 
	if (q == -1) cout << "-1\n"; 
	else {
		ll div; 
		for (ll i = 2; i * i <= q; i++) {
			if (q % i == 0) {
				cout << q / i << ' ' << q * (i - 1) / i << '\n'; 
				return;
			}
		}
	}
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}