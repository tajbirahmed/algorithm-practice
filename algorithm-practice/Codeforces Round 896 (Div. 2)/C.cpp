#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n, m; cin >> n >> m; 
	if (n == 1 and m == 1) {
			cout << 0 << '\n' << 0 << '\n';	
			return;
	}
	if (n == 1) {
		cout << 2 << '\n';
		for (int i = 0; i < m; i++) {
			cout << i << ' ';
		}
		cout << '\n'; 
		return; 
	}
	if (m == 1) {
		cout << 0 << '\n'; 
		for (int i = 0; i < n; i++) {
			cout << 0 << '\n';
		}
		return;
	}
	
	int a[n][m];
	memset(a, 0, sizeof a); 
	for (int i = 0; i < m; i++) {
		int ele = 1;
		for (int j = 0; j < n; j++) {
			a[j][i] = ele; 
			ele++;
			if (ele == m) ele = 1;
		}
		break; 
	}
	cout << min(n + 1, m) << '\n';
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[j][i] = (a[j][i - 1] + 1) % m; 
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}	