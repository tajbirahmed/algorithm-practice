#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	int n; cin >> n; 
	vector <ll> a(n); 
	ll sum = 0LL;  
	for (auto &i : a) {cin >> i; sum += i;} 
	if (sum % n) {
		cout << "no\n"; 
		return; 
	}
	ll tar = sum / n;
	vector <int> plus, minus;  
	for (int i = 0; i < n; i++) { 
		ll diff = a[i] - tar; 
		bool f = 0;
		for (ll j = 0; j < 60; j++) {
			for (ll k = 0; k < 60; k++) {
				ll p = -(1LL << k) + (1LL << j);
				if (p == diff) {
					// cout << p << " " << j << " " << k << endl;  
					f = 1;
					plus.push_back(j); 
					minus.push_back(k); 
					break; 
				}
			}
			if (f) break;
		}
		if (!f) {
			cout << "no\n"; 
			return;
		}
	}
	// for (int i = 0; i < plus.size(); i++) {
	// 	cout << plus[i] << ' ' << minus[i] << '\n';
	// }

	sort (plus.begin(), plus.end());
	sort (minus.begin(), minus.end());
	
	if (plus == minus) {
		cout << "yes\n"; 
	} else {
		cout << "no\n";
	}
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}