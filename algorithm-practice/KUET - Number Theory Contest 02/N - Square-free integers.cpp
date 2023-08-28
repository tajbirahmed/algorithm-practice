#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const int N = 1e7 + 1;; 
/*
	resource: https://en.wikipedia.org/wiki/M%C3%B6bius_function
*/
ll mobius[N]; 
bool pr[N]; 
void pre() {
	for (int i = 1; i < N; i++) {
		mobius[i] = 1;
		pr[i] = 1;
	}
	for (ll i = 2; i < N; i++) {
		if (pr[i]) {
			mobius[i] = -1;
			for (ll j = i + i; j < N; j += i) {
				pr[j] = 0;
				if (j % (i * i) == 0) {
					mobius[j] = 0;
				} else {
					mobius[j] *= (-1);
				}
			}
		}
	}
}
void solve() {
	ll n; cin >> n; 
	ll ans = 0; 
	for (ll i = 2; i * i <= n; i++) {
		ans -= (mobius[i] * (n / (i * i)));
		// cout << mobius[i] * (n / (i * i)) << '\n';
	}
	cout << n - ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}