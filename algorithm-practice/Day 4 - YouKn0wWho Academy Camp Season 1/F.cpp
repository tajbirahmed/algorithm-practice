#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n, m, k; cin >> n >> m >> k; 
	string s, t; cin >> s >> t; 
	bool f[26][26];
	memset(f, 0, sizeof f);  
	for (int i = 0; i + k - 1 < n; i++) {
		f[s[i] - 'a'][s[i + k - 1] - 'a'] = 1; 
	}
	ll cnt = 0;
	int freq[26] = {0}; for (int i = 0; i < m; i++) {freq[t[i] - 'a']++;}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			if (f[t[i] - 'a'][j]) cnt += freq[j];
		}
		freq[t[i] - 'a']--;
	}
	cout << cnt << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}