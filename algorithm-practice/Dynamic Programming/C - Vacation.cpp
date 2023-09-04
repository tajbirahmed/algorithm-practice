#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e5 + 1;
vector <vector <ll>> v; 
ll count(int i, int ind) {
	if (i == v.size()) 
		return 0;
	ll mx = -1; 
	if (ind == -1) {
		mx = max({count(i + 1, 0), count(i + 1, 1), count(i + 1, 2)}); 
	} else if (ind == 0){
		mx = max({count(i + 1)})
	}
}
void solve() {
	int n; cin >> n; 
	for (int i = 1; i <= n; i++) {
		ll a, b, c; cin >> a >> b >> c; 
		v.push_back({a, b, c});
	}
	// for (auto i : v[0]) cout << i << ' ';
	cout << count(0, -1);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}