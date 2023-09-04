#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n; cin >> n; 
	vector <ll> a(n); 
	for (auto &i : a) cin >> i;
	int cnt = 0; 
	for (int i = 1; i < n; i++) {
		if (a[i - 1] + 1 != a[i]) {
			++cnt; 
		}
	}	
	cout << cnt / 2 << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}