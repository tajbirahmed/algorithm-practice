#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; cin >> n; 
	int a[n], b[n];
	int mxw = -1, mxq = -1; 
	int cntw = 0, cntq = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i]; 
		if (a[i] >= mxw) {
			mxw = a[i];
			if (mxq >= b[i]) {
				mxq = b[i];
			}
		}	 
	}
	
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}