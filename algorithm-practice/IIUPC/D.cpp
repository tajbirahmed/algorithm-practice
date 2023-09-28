#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const int N = 2e5 + 10; 
map <int, int> mp[N]; 
void pre () {
	int spf[N];
	for (int i = 1; i < N; i += 1) {
		spf[i] = i; 
	}
	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j += i) {
			spf[j] = min(i, spf[j]);
		}
	}
	for (int i = 2; i < N; i++) {
		int x = i; 
		while (x > 1) {
			
		}
		for (auto p : mp[i - 1]) {
			mp[i][p.first] += p.second;
		}
	}
} 
void solve() {
	int n, m; 
	cin >> n >> m; 
	int a[n], b[m];
	map <int, int> ans;  
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		for (auto p : mp[a[i]]) {
			ans[p.first] += p.second; 
		}

	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		for (auto p : mp[b[i]]) {
			ans[p.first] -= p.second; 
		}
	}
	for (auto p : ans) {
		if (p.second < 0) {
			cout << "1\n"; 
			return;
		}
	}
	cout << "0\n";
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre(); 
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}