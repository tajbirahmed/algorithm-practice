#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;  
	while (1) {
		ll n, d; 
		cin >> n >> d;
		if (n == 0 and d == 0) {
			break; 
		} else if (n <= 1 and d == 1) {
			cout << "1\n"; 
			continue; 
		}
		map <int, int> m;  
		for (int i = 2; i <= n; i++) {
			ll x = i; 
			for (int j = 2; j * j <= x; j++) {
				if (x % j == 0) {
					int cnt = 0;
					while (x % j == 0) {
						x /= j; 
						++cnt;
					}
					m[j] += cnt;
				}
			}
			if (x > 1) m[x]++; 
		} 
		ll x = d;
		for (ll i = 2; i * i <= d; i++) {
			if (x % i == 0) {
				int cnt = 0; 
				while (x % i == 0) {
					++cnt; 
					x /= i; 
				}
				m[i] -= cnt;
			}
		}
		if (x > 1) m[x]--;
		bool f = 1;
		ll cnt = 1;
		for (auto i : m) {
			if (i.second < 0) f = 0;
			cnt *= (i.second + 1);
		}
		if (f) {
			cout << cnt << '\n';
		} else {
			cout << "0\n"; 
		}
	} 
}