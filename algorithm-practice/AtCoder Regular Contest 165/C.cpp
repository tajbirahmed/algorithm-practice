#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n, m; 
const int N = 2e5 + 1; 
vector <pair <int, ll>> adj[N]; 
void solve() {
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		int u, v;
		ll w; 
		adj[u].push_back({v, w}); 
		adj[v].push_back({u, w}); 
	}
	queue <int> q; 
	int col[n + 1]; 
	for (int i = 1; i <= n; i++) col[i] = -1;
	col[1] = 0;
	q.push(1); 
	while (!q.empty()) {
		int u = q.front(); 
		q.pop(); 
		for (auto v : adj[u]) {
			if (col[v] == -1) {
				col[v] = 1 - col[u]; 
				q.push(v); 
			}
		}
	}	
	    
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}