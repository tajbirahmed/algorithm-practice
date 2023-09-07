#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; 
	cin >> n; 
	int mx = 1000; 
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y; 
		mx = min(mx, x + (y - 1) / 2);
	}	
	cout << mx << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}