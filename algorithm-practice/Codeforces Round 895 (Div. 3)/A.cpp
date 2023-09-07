#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll a, b, c; cin >> a >> b >> c;
	ll x = abs (b - a); 
	ll y = (x + 1) / 2;
	cout << (y + c - 1) / c << '\n';	
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}