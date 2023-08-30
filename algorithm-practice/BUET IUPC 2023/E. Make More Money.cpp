#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n; 
	cin >> n; 
	ll a[n]; 
	for (int i = 0; i < n; i++ ) cin >> a[i]; 
	ll sum = a[n - 1];
	ll dest = n - 1;
	bool f = 1;
	for (int i = n - 2; i > 0; i--) {
			if (f)
				sum += 2 * a[i];
			else 
				sum = a[i];
			if (sum < 0) {
				dest = i;
				f = 1;
				continue;
			}
			f = 0;
			// if (sum > 0) {
	}
	sum = 0;
	for (int i = 0; i <= dest; i++) {
		sum += a[i];
	}
	// cout << dest << "<- dest\n";
	ll sum2 = 0;
	ll mx = 0;
	for (int i = dest - 1; i >= 0; i--) {
			sum2 += a[i];
			mx = max(mx, sum2);
	}
	cout << sum + mx; 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) { 
		solve(); 
		if (T) cout << '\n';
	}	
}	