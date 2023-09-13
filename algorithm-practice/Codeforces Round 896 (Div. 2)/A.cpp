#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; cin >> n; 
	int a[n]; 
	int XOR = 0;
	for (int i = 0; i < n; i++){ 
		cin >> a[i];
		XOR ^= a[i];
	} 
	if (XOR) {
		vector <pair <int, int>> p; 
		p.push_back({1, n}); 
		if (n & 1) {
			p.push_back({1, n - 1}); 
			p.push_back({n - 1, n});
			p.push_back({1, n}); 
		} else {
			p.push_back({1, n});
		}
		cout << p.size() << '\n'; 
		for (auto i : p) {
			cout << i.first << ' ' << i.second << '\n'; 
		}
	} else cout << "1\n1 " << n << '\n';  
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}