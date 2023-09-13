#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; cin >> n; 
	string s, t; cin >> s >> t; 
	ll ans = 0; 
	ll prev = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] < t[i]) {
			ans += n - i;
			prev = n - i;
		} else if (s[i] == t[i]) {
			ans += prev; 
		} else prev = 0;  
	}
	cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}