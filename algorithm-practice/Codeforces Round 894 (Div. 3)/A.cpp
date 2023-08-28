#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 



void solve() {
	int n, m;
	cin >> n >> m;
	string s[n]; for (int i = 0; i < n; i++) cin >> s[i]; 
	for (int j = 0; j < m; j++) {
		int i = 0;
		while (i < n and s[i][j] != 'v') i++;
		for (int k = j + 1; k < m; k++) {
			int p = 0; 
			while (p < n and s[p][k] != 'i') p++;
			for (int q = k + 1; q < m; q++) {
				int r = 0;
				while (r < n and s[r][q] != 'k') r++; 
				for (int x = q + 1; x < m; x++) {
					int y = 0;
					while (y < n and s[y][x] != 'a') y++; 
					if (s[y][x] == 'a') {
						cout << "YES\n"; 
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}