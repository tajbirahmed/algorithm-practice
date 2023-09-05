#include "bits/stdc++.h"
using namespace std; 

using ll = long long; 
const int N = 1e5 + 1;
ll lazy[4 * N]; 
ll t[4 * N];

void build(int i, int tl, int tr) {
    lazy[i] = 0;
    if (tl == tr) {
        t[i] = 0;
        return;
    }
    int mid = (tl + tr) / 2;
    build(2 * i, tl, mid); 
    build(2 * i + 1, mid + 1, tr);
}

void push(int i, int tl, int tr) {
    if (lazy[i] == 0) return;
    t[i] = t[i] + lazy[i] * (tr - tl + 1);
    if (tl != tr) {
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int n, int tl, int tr, int i, int j, ll val) {
    push(n, tl, tr);
    if (j < tl or i > tr) 
        return;
    if (i <= tl and tr <= j) {
        lazy[n] = val;
        push(n, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    update(2 * n, tl, mid, i, j, val);
    update(2 * n + 1, mid + 1, tr, i, j, val);
    t[n] = t[2 * n] + t[2 * n + 1];
}

ll query(int n, int tl, int tr, int i, int j) {
    push(n, tl, tr); 
    if (i > tr or tl > j) 
        return 0;
    if (i <= tl and tr <= j) return t[n];
    int mid = (tl + tr) / 2;
    return query(2 * n, tl, mid, i, j) + query(2 * n + 1, mid + 1, tr, i, j);
}

 
void solve() {
    int n; cin >> n;
    // build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        update(1, 1, n, i, i, x); 
    }
    int m; cin >> m; 
    while (m--) {
        int a, b; ll x;
        cin >> a >> b >> x;
        update(1, 1, n, a + 1, b + 1, x);
    }
    for (int i = 1; i <= n; i++) {
        cout << query(1, 1, n, i, i) << ' ';
    }
}
int main () {
    ios_base::sync_with_stdio(0);
      cin.tie(0);
      int T = 1; 
      // cin >> T; 
      while (T--) solve(); 
}