#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e5 + 2; 
int n; 	
ll a[N], c[N];   
void solve() {
	cin >> n; 
	multiset <int> voyaboho;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		voyaboho.insert(a[i]);
	}
	vector <int> sold;
	queue <int> q; 
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (voyaboho.find(i) == voyaboho.end()) q.push(i); 
	}
	while (q.size()) {
		auto i = q.front(); 
		sold.push_back(i);
		q.pop(); 
		auto it = voyaboho.find(a[i]); 
		voyaboho.erase(it); 
		if (voyaboho.find(a[i]) == voyaboho.end()) q.push(a[i]);
	}
	vector <bool> has(n + 1, 0);
	for (auto i : voyaboho) {
		int curr = i; 
		if (has[i]) continue; 
		has[i] = 1;
		bool f = 0; 
		int mn = c[curr];  
		int tmp = i;  
		while (!f || curr != i) {
			f = 1;
			if (mn > c[curr]) {
				tmp = curr; 
				mn = c[curr]; 
			} 
			has[curr] = 1;
			curr = a[curr]; 
		}
		curr = a[tmp]; 
		while (curr != tmp) {
			sold.push_back(curr); 
			curr = a[curr];
		}
		sold.push_back(tmp);
	}
	for (auto i : sold) cout << i << ' ';
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}