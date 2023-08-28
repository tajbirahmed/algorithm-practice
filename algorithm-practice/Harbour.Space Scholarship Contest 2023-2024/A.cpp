#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	int n, x, y;
	cin >> x >> y >> n;
	int a[n]; a[n - 1] = y;
	int k = 1;
	for (int i = n - 2; i >= 0; i--) {
		a[i] = a[i + 1] - k;
		++k;
	}	
	if (a[0] >= x) {
		for (int i = 0; i < n; i++) {
			if (i)
				cout << a[i] << ' '; 
			else 
				cout << x << ' '; 
		}
		cout << '\n';
	} else {
		cout << "-1\n";
	}

}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}