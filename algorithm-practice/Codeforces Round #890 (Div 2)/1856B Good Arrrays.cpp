#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e5+1;
int n, a[N];
void solve() {
	cin >> n;
	ll sum = 0;
	int cntOne = 0;
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
		sum += a[i];
		if (a[i] == 1) cntOne++; 
	}
	if (sum < cntOne + n || n == 1) {
		cout << "NO\n"; 
	} else cout << "YES\n";
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}