#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
struct Edge {
    int u, v; 
    ll w; 
};
ll n, m; 
const int N = 1e5 + 1;
int parent[N]; 
vector <Edge> edges;
bool cmp(Edge &a, Edge &b) {
    return a.w < b.w;
}
int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b) {
    a = find(a);
    b = find(b); 
    if (a != b) 
        parent[b] = a;
}
void solve() {
    cin >> n >> m; 
    for (int i = 1; i <= m; i++) {
        Edge e; 
        cin >> e.u >> e.v >> e.w; 
        edges.push_back(e);    
    }
    sort(edges.begin(), edges.end(), cmp); 
    ll cost = 0LL; 
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            cost += e.w;
            ++cnt;  
            Union(e.u, e.v);
        }
    }
    if (cnt != n - 1) {
        cout << "Not Possible\n"; 
    } else {
        cout << m - n + 1 << ' ' << cost << '\n';
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    // cin >> T; 
    while (T--) solve(); 
}