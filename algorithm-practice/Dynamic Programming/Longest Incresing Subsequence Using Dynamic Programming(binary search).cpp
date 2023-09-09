#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n;
const int N  = 1e5 + 1; 
int a[N], d[N]; 
void lis () {
	d[0] = INT_MIN; 
	for (int i = 1; i < n; i++) d[i] = INT_MAX;
	for (int i = 0; i < n; i++) {
		int l = upper_bound(d, d + n, a[i]) - d; 
		if (d[l - 1] < a[i] and a[i] < d[l]) {
			d[l] = a[i];
		}
	}
	for (int i = 1; i < n; i++) {
		if (d[i] < INT_MAX) cout << d[i] << ' ';
	}
}
void solve() {
	cin >> n;
	for (int i = 0; i  < n; i++) cin >> a[i];
	lis();
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}