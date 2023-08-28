#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	ll n, m;
	cin >> n >> m; 
	vector <pair <ll, ll>> v;
	for (int i = 0; i < m; i++) {
		ll x, y; cin >> x >> y;
		v.push_back({y, x});
	}
	sort(v.begin(), v.end()); 
	ll gcd[m];
	gcd[0] = __gcd(v[0].second, n);  
	for (int i = 1; i < m; i++) {
		gcd[i] = __gcd(gcd[i - 1], v[i].second);
	}
	ll sum = (n - gcd[0]) * v[0].first;
	for (int i = 0; i + 1 < m; i++) {
		sum += v[i + 1].first * (gcd[i] - gcd[i + 1]);
	}

	if (gcd[m - 1] != 1) 
		cout << "-1\n";
	else 
		cout << sum << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	// cin >> T; 
  	while (T--) solve(); 
}