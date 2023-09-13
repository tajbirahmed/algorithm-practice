#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; cin >> n; 
	vector <ll> a(n); 
	for (auto &i : a) cin >> i; 
		ll prod = 1LL; 
	int l = 0, r = 0;
	vector <vector <ll>> segProduct, preProduct, postProduct; 
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			if (prod != 1) {
				r = i - 1; 
				segProduct.push_back({prod, l, r});
			}
			prod = 1;
		} else {
			if (prod == 1) l = i; 
			prod *= a[i];
		}
	}
	if (prod != 1) {
		segProduct.push_back({prod, l, n - 1});
	}

}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}