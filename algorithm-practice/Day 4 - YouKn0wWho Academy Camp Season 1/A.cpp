#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cout << i << '\n';
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