#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const int N = 2e5 + 1; 
int a[N], b[N]; 
void solve() {
	int n, m; 
	cin >> n >> m; 
	int p = 0, q = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p ^= a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i]; 
		q |= b[i]; 
	}
	int mn = 0;
	for (int i = 1; i <= n; i++) {
		mn ^= a[i] | q;
	}
	if (mn > p) swap(mn, p);
	cout << mn << ' ' <<  p << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}