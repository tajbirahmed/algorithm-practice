#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	ll n; cin >> n; 
	ll a[n]; 
	bool pos = 0;
	bool neg = 0;
	ll mx = -1;
	ll mn = 21; 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0) 
			pos = 1;
		if (a[i] < 0)
			neg = 1;
	}	
	vector <pair <int, int>> v;
	if (pos) {
		neg = 0;
		int idx;
		for (int i = 0; i < n; i++) {
			if (a[i] > mx) {
				mx = a[i];
				idx = i; 
			}
		}
		while (a[idx] < 64) {
			a[idx] += a[idx];
			v.push_back({idx + 1, idx + 1});
		}
		a[0] += a[idx];
		v.push_back({1, idx + 1});
		for (int i = 1; i < n; i++) {
			a[i] += a[i - 1];
			a[i] += a[i - 1];
			v.push_back({i + 1, i}); 
			v.push_back({i + 1, i}); 
		}
	}
	if (neg) {
		int idx;
		for (int i = 0; i < n; i++) {
			if (a[i] < mn) {
				mn = a[i];
				idx = i; 
			}
		}
		while (a[idx] > -64) {
			a[idx] += a[idx];
			v.push_back({idx + 1, idx + 1});
		}
		a[n - 1] += a[idx];
		v.push_back({n, idx + 1});
		for (int i = n - 1; i >= 1; i--) {
			a[i - 1] += a[i]; 
			a[i - 1] += a[i];
			v.push_back({i, i + 1});
			v.push_back({i, i + 1});
		}
	}
	cout << v.size() << '\n';
	for (auto p : v) {
		cout << p.first << ' ' << p.second << '\n'; 
	}
	// for (int i = 0; i < n; i++) cout << a[i] << ' ';
	// cout << '\n'; 
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}