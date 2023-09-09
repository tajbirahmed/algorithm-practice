#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e5 + 1;
int spf[N];  
vector <bool> p(N, 0);
int h[N]; 
vector <int> adj[N];
set <int> multiple[N]; 
bool vis[N];
int cnt=0;
set<int> primes;
void pre () {
    for (int i = 2; i < N; i++) spf[i] = i, p[i] = 1; 
    for (int i = 2; i < N; i++) {
        if (p[i]) {
            for (int j =  2 * i; j < N; j += i) {
                spf[j] = min(spf[j], i);
                p[j] = 0; 
            }
        }
    }
}
void dfs(int x, int u){
    vis[u]=true;
    cnt++;
    for(auto v : adj[u]){
        if(!vis[v] and multiple[x].find(v) != multiple[x].end()){
            dfs(x, v);
        }
    }
}
void solve() {
    int n; cin >> n; 
    for (int i = 1; i <= n; i++) { 
        cin >> h[i]; 
        int x = h[i]; 
        while (x > 1) {
            multiple[spf[x]].insert(i);
            primes.insert(spf[x]);
            x /= spf[x];
        }
    }
    for (int i = 1; i < n; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx=0;
    for(auto u : primes){
        memset(vis, 0, sizeof(vis));
        for(auto i : multiple[u]){
            if(!vis[i]){
                cnt=0;
                dfs(u, i);
                mx = max(cnt, mx);
            }
        }
    }
    cout << mx << '\n';
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    pre(); 
    // cin >> T; 
    while (T--) solve(); 
}