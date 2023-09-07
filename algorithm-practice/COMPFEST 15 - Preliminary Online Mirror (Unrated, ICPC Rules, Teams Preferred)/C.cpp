#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n;
const int N = 1e5 + 2;
vector <pair <ll, bool>> adj[N];
ll inv[N], oneCnt[N], zeroCnt[N];
bool vis[N]; 
const ll mod = 998244353LL; 
void dfs(int parent) {
	vis[parent] = true;
	for (auto i : adj[parent]) {
		int child = i.first, w = i.second; 
		if (!vis[child]) {
			dfs(child); 
		}
		zeroCnt[parent] = (zeroCnt[parent] + zeroCnt[child]) % mod + (w == 0);
		inv[parent] = (inv[parent] + inv[child]) % mod;
		inv[parent] = (inv[parent] + ((oneCnt[parent] % mod) * (zeroCnt[child] % mod)) % mod) % mod;;
		if (w) 
			inv[parent] = (inv[parent] + zeroCnt[child]) % mod;
		else
			inv[parent] = (inv[parent] + oneCnt[parent]) % mod;
		// inv[parent] += (ll)inv[child] + (ll)((oneCnt[parent] * zeroCnt[child])) + 
					// (ll)((zeroCnt[child]) * (w == 1)) + (ll)(oneCnt[parent] * (w == 0));
		// inv[parent] =  (inv[parent] % mod + mod) % mod;
		oneCnt[parent] = (oneCnt[parent] + oneCnt[child]) % mod + (w == 1);
	}
}

void solve() {
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		int q; cin >> q; 
		while (q--) {
			int x; bool w; cin >> x >> w; 
			adj[i].push_back({x, w});
		}
	}
	dfs(1);
	cout << inv[1] << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}
// 942385756
// 942385756