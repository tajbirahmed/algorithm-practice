#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	int n; cin >> n; 
	int a[n]; 
	for (int i = 0; i < n; i++) cin >> a[i]; 
	int mex = -1; 
	sort (a, a + n); 
	if (a[0] != 0) mex = 0; 
	else {
		for (int i = 1; i < n; i++) {	
			if (a[i] != a[i - 1] + 1 ) {
				mex = a[i - 1] + 1; 
				break; 
			}
		}
		if (mex == -1) mex = a[n - 1] + 1;
	}
	cout << mex << '\n'; 
	int ans; cin >> ans; 
	while (ans != -1) {
		cout << ans << '\n'; 
		cin >> ans; 
	}
}
int main () {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	fflush(stdout);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}