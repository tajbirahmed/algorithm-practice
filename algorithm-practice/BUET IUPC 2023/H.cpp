#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	ll ans1 = min(abs(x2 - x1), min(x1, x2) + 16 - max(x1, x2)); 
	ll ans2 = min(abs(y2 - y1), min(y2, y1) + 20 - max(y1, y2)); 
	cout << ans1 + ans2 << '\n';

}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}