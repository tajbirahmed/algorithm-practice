#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	vector <int> v{1, 1, 2, 3, 4, 6, 6, 6}; 
	auto it = upper_bound(v.begin(), v.end(), 4) - v.begin(); 
	cout << it << '\n';	
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}