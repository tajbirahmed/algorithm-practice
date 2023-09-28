#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	int n; 
	cin >> n; 
	char c; 
	int i = 2; 
	cin >> c;  
	char x; 
	int cnt = 0;
	while (i <= n) {
		cin >> x;
		if (x == c) ++cnt;
		c = x;
		++i;
	}
	cout << cnt << '\n'; 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	//  cin >> T; 
	while (T--) solve(); 
}