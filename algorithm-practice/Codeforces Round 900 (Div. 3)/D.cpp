#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n, k; 
	cin >> n >> k; 
	char s[n]; 
	for (int i = 0; i < n; i++) cin >> s[i]; 
	int l[k], r[k]; 
	for (int i = 0; i < k; i++) {
		cin >> l[i];
		l[i]--;
	}
	for (int i = 0; i < k; i++) {
		cin >> r[i];
		r[i]--;
	}	
	int q; cin >> q; 
	vector <pair <int, int>> vp;
	while (q--) {
		int x; cin >> x; x--;
		int p = lower_bound(r, r + k, x) - r; 
		int a = min(x, l[p] + r[p] - x);
		int b = max(x, l[p] + r[p] - x);  
		vp.push_back({a, b});
		
	} 
	int f[n]; 
	memset (f, 0, sizeof f); 
	for (int i = 0; i < vp.size(); i++) {
		f[vp[i].first] += 1; 
		if (vp[i].second + 1 < n) {
			f[vp[i].second + 1] -= 1;
		}
	}
	for (int i = 1; i < n; i++) {
		f[i] += f[i - 1];
	}
	for (int i = 0; i < k; i++) {
		int a = l[i]; 
		int b = r[i]; 
		while (a < b) {
			if (f[a] & 1) {
				swap(s[a], s[b]);
			}
			a++;
			b--;
		}
	}
	for (int i = 0; i < n; i++) cout << s[i];
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}

