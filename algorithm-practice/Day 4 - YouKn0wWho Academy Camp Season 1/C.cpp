#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	int n; cin >> n; 
	vector <ll> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	for (int i = 0; i < n; i++) {
		cin >> b[i]; 
	}
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
	ll sum = 0; 
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n - i - 1]; 	
	}
	cout << sum << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	int t = 1; 
	while (T--) { 
		cout << "Case #" << (t++) << ": ";
		solve(); 
	}
}