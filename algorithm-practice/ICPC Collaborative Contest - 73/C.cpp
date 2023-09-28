#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	set <int> s; 
	int n, m;
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}	
	vector <int> v; 
	for (int i = 1; i <= m; i++) {
		int x; 
		cin >> x; 
		s.erase(x);
		v.push_back(x);
	}
	for (auto i : v) {
		vector <int> temp; 
		for (auto p : s) {
			if (p < i) {
				temp.push_back(p);
			} else break; 
		}
		for (int j = 0; j < temp.size(); j++) {
			if (s.find(temp[j]) != s.end()) {
				s.erase(temp[j]); 
			}
			cout << temp[j] << '\n';
		}
		cout << i << '\n';
	}
	for (auto i : s) cout << i << '\n';
} 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}