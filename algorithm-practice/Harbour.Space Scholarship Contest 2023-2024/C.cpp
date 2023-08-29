#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n, x;
	cin >> n; 
	x = n; 
	vector <bool> bits; 
	while (n) {
		bits.push_back(n & 1); 
		n >>= 1; 
	}
	reverse(bits.begin(), bits.end()); 
	// for (auto i : bits) cout << i;
	ll p = 1;
	vector <ll> diffs; 
	diffs.push_back(x);
	if (x > 1){	
		for (int i = bits.size() - 1; i > 0; i--) {
			if (bits[i]) {
				x -= p; 
				diffs.push_back(x);
			}
			p *= 2;
		}
		while (x != 1) {
			diffs.push_back(x - (x / 2));
			x -= (x / 2); 
		}
	}
	cout << diffs.size() << '\n';
	for (auto i : diffs) cout << i << ' ';
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}