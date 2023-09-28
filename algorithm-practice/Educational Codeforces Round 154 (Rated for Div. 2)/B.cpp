#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	string s, t;
	cin >> s >> t;  
	int n = s.size(); 
	if (s[0] != t[0] or s[n - 1] != t[n - 1]) {
		cout << "NO\n"; 
		return; 
	}	
	int l = n - 2, r = n - 1; 
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == t[i]) {
			l--;
		} else {
			while (l >= )
		}
	}
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}