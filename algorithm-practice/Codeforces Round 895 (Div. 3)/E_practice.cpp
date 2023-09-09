#include "bits/stdc++.h"
#define int long long
using namespace std; 
using ll = long long; 
int n; 
const int N = 1e5 + 1; 
int a[N], pref[N]; 
string s; 
void solve() {
	cin >> n; 
	for (int i = 0; i < n; i++) { 
		cin >> a[i];
		if (i)
			pref[i] = a[i] ^ pref[i - 1]; 
		else pref[i] = a[i];
	}
	cin >> s; 
	int xor0 = 0, xor1 = 0; 
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') xor0 ^= a[i]; 
		else xor1 ^= a[i]; 
	} 
	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp; 
		if (tp == 1) {
			int l, r; cin >> l >> r;
			l--, r--; 
			ll temp_xor = pref[r];
			if (l) temp_xor	^= pref[l - 1];
			xor0 ^= temp_xor;
			xor1 ^= temp_xor; 
		} else {
			int x; cin >> x;
			if (x) cout << xor1 << ' '; 
			else cout << xor0 << ' '; 
		}
	}
	cout << '\n';
}
int32_t main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}