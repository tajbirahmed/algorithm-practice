#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int a, b; 
	cin >> a >> b;
	int cnt1 = 0, cnt2 = 0; 
	while (a) {
		if (a & 1) ++cnt1;
		a /= 2;
	}	
	while (b) {
		if (b & 1) ++cnt2; 
		b /= 2; 
	}
	if (cnt1 == cnt2) cout << "good\n"; 
	else cout << "bad\n";
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}