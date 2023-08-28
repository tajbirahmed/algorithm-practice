#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

bool prime(ll x) {
	if (x % 2 == 0) 
		return false;  
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	ll n; cin >> n;
	map<ll, int> m;
	vector <ll> p;
	p.push_back(n);
	while (n > 1) {
		// cout << n << ' ';
		bool f = 0;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0 and m[n / i] < 2) {
				// cout << i << ' ';
				if (prime(n - (n / i))) {
					continue;
				} 
				p.push_back(n - (n / i)); 
				n -= (n / i);
				f = 1;
				m[n / i]++;
				break;
			}
		}
		if (!f) {
			if (n == 1) 
				break;
			// cout << n - 1 << ' ';
			
			if (prime(n)){
				p.push_back(n - 1);
				n -= 1;
			} else {
				p.push_back(n - 2);
				n -= 2; 
			}
		}
	}	
	cout << p.size() << '\n'; 
	for (int i  = 0; i + 1 < p.size(); i++){ 
		cout << p[i] << ' ';
	}
	cout << 1 << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}