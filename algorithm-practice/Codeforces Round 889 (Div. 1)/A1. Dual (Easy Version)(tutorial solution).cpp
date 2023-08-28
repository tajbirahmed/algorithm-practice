/**
	if all the elements are negative 
	we can make the array non decreasing by following move
	
	(n - 1, n), (n - 2, n - 1), (n - 3, n - 2) .....

	if any positive element exists -> 
		make that element > 20 by only 5 moves
			proof 1 -> 2 -> 4 -> 8 -> 16 -> 32
	then make a2 biggest by (2, max)
	then make a3 biggest by (3, 2)
	then make a4 biggest by (4, 3)
*/
#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	ll n; cin >> n;
	vector <ll> a(n);
	bool neg = 1; 
	for (int  i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			neg = 0;
		}
	}	
	vector <pair <int, int>> v;
	if (neg) {
		for (int i = n; i >= 2; i--) {
			v.push_back({i - 2, i - 1});
			a[i - 2] += a[i - 1]; 
		}
	} else {
		auto mx = max_element(a.begin(), a.end()); 
		int idx = distance(a.begin(), mx);
		while (a[idx] <= 20) {
			a[idx] += a[idx]; 
			v.push_back({idx, idx});
		}
		for (int i = 1; i < n; i++) {
			if (a[i] < 0) {
				a[i] += a[idx]; 
				v.push_back({i, idx});
			}
			a[i] += a[idx];
			v.push_back({i, idx});
			idx = i;
		}
	}
	cout << v.size() << '\n'; 
	for (auto p : v) {
		cout << p.first + 1 << ' ' << p.second + 1 << '\n'; 
	}
	
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}