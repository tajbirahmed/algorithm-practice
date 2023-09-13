#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
bool cmp(pair <int, int> a, pair<int, int> b) {
	return a.second > b.second; 
}
void solve() {
	int n; cin >> n;
	vector <int> a(n);
	vector <pair <int, int>> v;  
	for (int i = 0; i < n; i++) { 
		cin >> a[i];
		v.push_back({i, a[i]}); 
	}	
	sort(v.begin(), v.end(), cmp);
	vector <int> x(n); 
	for (int i = 0; i < n; i++) {
		x[v[i].first] = i + 1;
	}
	for (auto i : x) cout << i << ' ';
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}