#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

const int N = 1e7 + 1;
ll spf[N];

void pre () {
	for (int i = 1; i < N; i++) {
		spf[i] = i;
	}
	for (ll i = 2; i < N; i++) {
		for (ll j = 2 * i; j < N; j += i) {
			spf[j] = min(i, spf[j]);
		}
	}
}

void solve() {
	ll x, y;
	cin >> x >> y; 
	ll diff = y - x; 
	if (diff == 1) {
		cout << "-1\n"; 
		return;
	}
	set <ll> prf; 
	while (diff > 1) {
		prf.insert(spf[diff]); 
		diff /= spf[diff];
	}
	ll mx = 1e9;
	for (auto p : prf) {
		ll q = p - x % p; 
		if (x % p == 0) 
			q = 0;
		mx = min(q, mx);
	}
	cout << (mx == -1e9 ? -1 : mx) << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	pre();
  	cin >> T; 
  	while (T--) solve(); 
}

/*
	gcd(x + n, y + n) = z != 1
	(x + n) = (y + n) mod z
	x - y = 0 mod z
*/