#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll m, D; 
	cin >> D >> m; 
	ll d[m]; 
	int over[m];
	over[0] = 0;
	for (int i = 0; i < m; i++) {
		cin >> d[i];
		if (i) 
			over[i] = d[i - 1] % 7;
	}		
	int cnt = d[0] >= 13 ? 1 : 0; 
	
	for (int i = 1; i < m; i++) {
		if (d[i - 1] % 7 == 0 and d[i] >= 13) ++cnt;
		d[i] += d[i - 1];
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