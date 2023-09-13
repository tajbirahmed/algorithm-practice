#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; cin >> n;
	vector <ll> v(n); 
	for (auto &i : v) cin >> i; 
	int l = 0, r = n - 1; 
	while (v[l] == 1) l++; 
	while (v[r] == 1) r--; 
	if (l > r) {
		cout << "1 1\n"; 
		return;
	}
	ll mx  = (1LL << 60); 
	ll prod = 1LL; 
	for (int i = l; i <= r; i++) {
		if (prod < mx / v[i]) 
			prod *= v[i]; 
		else prod = mx; 
	}		

	if (prod >= mx) {
		cout << l + 1 << ' ' << r + 1 << '\n'; 
		return; 
	}
	int L = l, R = r;  
	ll sum = 0LL, ans = 0LL;
	for (auto i : v) sum += i; 
	for (int i = l; i <= r; i++) {
		if (v[i] == 1) continue; 
		prod = 1LL; 
		ll tmpSum = 0;
		for (int j = i; j <= r; j++) {
			prod *= v[j];
			tmpSum += v[j];
			if (ans < sum - tmpSum + prod) {
				L = i; 
				R = j;
				ans = sum - tmpSum + prod;
			}
		}
	}
	cout << L + 1 << ' ' << R + 1 << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}