#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

bool sign(ll a, ll b) {
	return (a > 0 and b > 0) or (a < 0 and b < 0);
}

void solve() {
	ll n; cin >> n; 
	vector <ll> a(n);
	bool post = 0, negt = 0;
	for (auto &i : a) { 
		cin >> i;
		if (i > 0){ 
			post = 1;
		}
		if (i < 0){
			negt = 1;
		}
	} 
	vector <pair <int, int>> v;
	if (post and !negt) {
		for (int i = 1; i < n; i++) {
			v.push_back({i, i -1});
		}
	} else if (negt and !post) {
		for (int i = n - 1; i >= 1; i--) {
			v.push_back({i - 1, i});
		}
	} else if (!post and !negt) {
		//
	} else {
		vector <ll> b;
		for (int i = 0; i < n; i++) {
			b.push_back(a[i]);
		}
		vector<pair <int, int>> pos; 
		ll mx = -1;
		int idx = 0;
		ll mn = 21;
		for (int i = 0; i < n; i++) {
			if (a[i] > mx) {
				mx = a[i];
				idx = i;
			}
			if (a[i] < mn) {
				mn = a[i];
			}
		}
		while (a[idx] < abs(mn)) {
			a[idx] += a[idx]; 
			pos.push_back({idx, idx}); 
		}
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {
				pos.push_back({i, idx});
				a[i] += a[idx];
			}
		}
		for (int i = 1; i < n; i++) {
			if (a[i - 1] > a[i]) {
				pos.push_back({i, i - 1});
				a[i] += a[i - 1];
			}
		}
		mn = 21;
		idx = 0; 
		for (int i = 0; i < n; i++) {	
			if (b[i] < mn) {
				mn = b[i]; 
				idx = i; 
			}
		}
		vector <pair <int, int>> neg;
		while (abs(b[idx]) < mx) {
			b[idx] += b[idx]; 
			neg.push_back({idx, idx}); 
		}
		for (int i = 0; i < n; i++) {
			if (b[i] > 0) {
				b[i] += b[idx];
				neg.push_back({i, idx});
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			if (b[i] < b[i - 1]) {
				b[i - 1] += b[i];
				neg.push_back({i - 1, i});
			}
		}
		if (pos.size() <= neg.size()) {
			v = pos;
		} else v = neg;
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