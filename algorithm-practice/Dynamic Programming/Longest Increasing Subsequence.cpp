#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n; 
const int N = 1e5 + 1; 
int a[N], d[N], p[N]; 
void lis() { 
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] and d[i] < d[j] + 1) {
				d[i] = d[j] + 1; 
				p[i] = j;
			}
		}
	}
	int ans = 0, pos; 
	for (int i  = 0; i < n; i++) {
		if (d[i] > ans)  {
			ans = d[i]; 
			pos = i; 
		}
	}
	// one way
	vector <int> v; 
	while (pos != -1) {
		v.push_back(a[pos]); 
		pos = p[pos];
	}
	reverse(v.begin(), v.end());
	//for (auto i : v) cout << i << ' ';
	
	cout << '\n';
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		d[i] = 1;
		p[i] = -1; 
	}
	lis(); 
	for (int i = 0; i < n; i++) cout << d[i] << ' ';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}