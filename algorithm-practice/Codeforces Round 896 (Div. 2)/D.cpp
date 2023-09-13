#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	int n; cin >> n; 
	int a[n]; 
	ll sum = 0; 
	for (int i = 0; i < n; i++) { 
		cin >> a[i]; 
		sum += a[i]; 
	} 
	if (sum % n) {
		cout << "No\n"; 
		return; 
	}
	ll x = sum / n;  
	map <int, int> m; 
	for (int i = 0; i < n; i++) {
		if (x == a[i]) {
			m[x]++;
			continue; 
		}
		ll diff = abs(x - a[i]);
		if (__builtin_popcountll(diff) == 1) {
			if (x > a[i]) 
				m[diff]++;
			else 
				m[diff]--;
		} else {
			cout << "No\n"; 
			return;
		}
	}

}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}