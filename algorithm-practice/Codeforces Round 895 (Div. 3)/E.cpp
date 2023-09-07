#include "bits/stdc++.h"
using namespace std; 
using ll = long long int; 
const ll mx = 1e18;
const int N = 1e5 + 1;
ll t[4 * N]; 
ll lazy[4 * N]; 

void push(int x, int tl, int tr) {
	if (lazy[x] == 0) return; 
	t[x] += lazy[x];
	if (tl != tr) {
		lazy[2 * x] += lazy[x];
		lazy[2 * x + 1] += lazy[x];		
	}
	lazy[x] = 0LL;
}
void update(int x, int tl, int tr, int i, int j) {
	push(x, tl, tr);
	if (i > tr or j < tl) 
		return; 
	if (i <= tl and tr <= j) {
		lazy[x] = !lazy[x]; 
		push(x, tl, tr);
		return;
	}
	int mid = (tl + tr) / 2;
	update(2 * x, tl, mid, i, j, val); 
	update(2 * x + 1, mid + 1, tr, i, j, val);
	t[x] = min(t[2 * x], t[2 * x + 1]);
}
ll query(int x, int tl, int tr, int i, int j) {
	push(x, tl, tr); 
	if (i > tr or j < tl) 
		return mx;
	if (i <= tl and tr <= j) 
		return t[x];
	int mid = (tl + tr) / 2;
	return min(query(2 * x, tl, mid, i, j), query(2 * x + 1, mid + 1, tr, i, j));
}
void solve() {
	int n, m; cin >> n >> m;
	// build(1, 1, n);
	// cout << mx << '\n';
	while (m--) {
		int c; cin >> c;
		if (c == 1) {
			int l, r;
			ll v; cin >> l >> r >> v;
			l++;
			update(1, 1, n, l, r, v);
		} else {
			int j; 
			int i; cin >> i >> j; i++;
			cout << query(1, 1, n, i, j	) << '\n';
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