#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n; 
	cin >> n; 
	int cnt = 0; 
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) n /= i; 
			++cnt;
			if (cnt == 2) break;
		}
	}	
	if (n > 1 and cnt < 2) ++cnt;
	if (cnt == 2) cout << "Yes\n"; 
	else cout << "No\n";
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}