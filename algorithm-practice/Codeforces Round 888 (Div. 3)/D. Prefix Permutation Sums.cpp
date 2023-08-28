#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

bool is_permutation(vector<ll> &a, int n) {
	vector <bool> h(n + 1, false);
	if (a[0] > n) return false;
	h[a[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] <= 0 or a[i] - a[i - 1] > n) {
			return false; 
		}
		h[a[i] - a[i - 1]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!h[i]) {
			return false; 
		}
	}
	return true;
}

void solve() {
	ll n; cin >> n; 
	vector <ll> a;
	for (int i = 0; i + 1 < n; i++) {ll x; cin >> x; a.push_back(x);}
	if (a.back() != (n * (n + 1) / 2)) {
		a.push_back(n * (n + 1) / 2); 
		if (is_permutation(a, n)) cout << "YES\n"; 
		else cout << "NO\n";
		return;
	}
	map <ll, ll> cnt;
	set <ll> cntgt1;
	cnt[a[0]]++;
	for (int i = 1; i + 1 < n; i++) {
		cnt[a[i] - a[i - 1]]++;
		if (cnt[a[i] - a[i - 1]] > 1) cntgt1.insert(a[i] - a[i - 1]); 
	}
	if (cntgt1.size() > 1 || (cntgt1.size() == 1 and cnt[*cntgt1.begin()] > 2)) {
		cout << "NO\n";
		return;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			++res;
		}
	}
	if (res != 2) {
		cout << "NO\n"; 
	} else cout << "YES\n";
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}