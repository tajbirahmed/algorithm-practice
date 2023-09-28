#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; cin >> n; 
	int k; cin >> k; 
	int a[n]; 
	for (int i = 0; i < n; i++) cin >> a[i]; 
	int mn = 1e6; 
	for (int i = n - k; i < n; i++) {
		mn = min(a[i], mn);
	}
	int i; 
	
	for (i = n - k; i > 1; i--) {
		if (a[i] < a[i - 1]) break; 
	}	 
	int mx = 1, cnt = 1;  
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) ++cnt;
		else {
			mx = max (mx, cnt); 
			cnt = 1;
		}
	}
	if (cnt != 1) mx = max (mx, cnt);
	if (mx < k) {
		sort (a + i, a + i + k); 
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	} else {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}