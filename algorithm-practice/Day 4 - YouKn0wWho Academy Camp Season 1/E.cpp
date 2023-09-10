#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int m; cin >> m; 
	if (m == 1) {
		cout << "2\n1 1\n"; 
		return;
	}
	vector <int> v; 
	v.push_back(1); 
	v.push_back(2); 
	int x = v[v.size() - 1] + v[v.size() - 2];
	while (x <= m) {
		v.push_back(x); 
		x = v[v.size() - 1] + v[v.size() - 2];
	}	
	v.push_back(v[v.size() - 2]); 
	cout << v.size() << '\n';
	for (auto i : v) cout << i << ' ';
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}