#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n;
	cin >> n; 
	ll a[n], sum = 0; 
	for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];} 
	sort (a, a + n); 
	bool f = 1;
	for (int i = 1; i < n; i++) {
		if ((a[i] - a[i - 1]) % 2 != 0) f = 0;
	}
	if (f) cout << "yes\n"; 
	else cout << "no\n";
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}