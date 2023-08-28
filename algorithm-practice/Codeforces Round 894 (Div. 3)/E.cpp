#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	ll w, f; cin >> w >> f;
	ll inw = 0, in_f = 0;
	int n; cin >> n; ll a[n]; 
	for (int i = 0; i < n; i++) cin >> a[i];
	sort (a, a + n);
	reverse(a, a + n);
	ll t = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > inw and a[i] > in_f) {
			ll x = (a[i] - inw + w - 1) / w; 
			ll y = (a[i] - in_f + f - 1) / f;
			t += min(x, y); 
			inw += min(x, y) * w; 
			in_f += min(x, y) * f;
		}
		if (inw > in_f) 
			inw -= a[i]; 
		else 
			in_f -= a[i];	
	}
	cout << t << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}