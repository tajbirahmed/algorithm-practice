#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 2e5 + 1;  
vector <pair<int, bool>> v[N];
vector <bool> Z; 
ll mod = 998244353LL; 
ll n;
ll z[N]; 
ll dfs(int u) {
	for (auto x : v[u]) {
		Z.push_back(x.second); 
		dfs(x.first);
	}

}

void solve() {
		cin >> n; 

		for (int i = 1; i <= n; i++) {
			int m; cin >> m; 
			for (int j = 1; j <= m; j++) {
				int x; bool w; cin >> x >> w; 
				v[i].push_back({x, w}); 
			}
		}
		dfs(1LL); 
		int zero = 0;
		ll ans = 0LL;
		 
		for (int i = Z.size() - 1; i >= 0; i--) {
			if (Z[i]) {
				ans += zero; 
				ans %= mod;
			}
			else
				zero++; 
		}
		cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	// cin >> T; 
	while (T--) solve(); 
}