#include "bits/stdc++.h"
using namespace std; 
/*
	link : https://codeforces.com/blog/entry/97164?#comment-861094
*/
using ll = long long; 
void solve() {
	ll a, b, x;
	cin >> a >> b >> x;
	if (a < b) swap(a, b); 
	while (a > x and b > 0) { 
		if ((x - a % b) % b == 0) a = x; 
		else a = a % b;
		swap(a, b);
	}	
	if (b == x || a == x) cout << "YES\n"; 
	else cout << "NO\n";
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}