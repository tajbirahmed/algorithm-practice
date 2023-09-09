#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n, k; 
	cin >> n >> k;  
	if (k){
		for (int i = 2; i <= k; i++) {
			cout << i << ' ';
		}	
		cout << 1 << ' ';
		for (int i = k + 1; i <= n; i++) {
			cout << i << ' ';
		}
		cout << '\n';
	} else cout << "-1\n";
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}