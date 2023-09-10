#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e5 + 5; 
struct node {
	int lazy; 
	int XOR[2]; 
	node () {
		lazy = XOR[0] = XOR[1] = 0; 

	}
};

node t[4 * N];
int a[N];
string s; 
node merge(node x, node y) {
	node temp; 
	temp.XOR[0] = x.XOR[0] ^ y.XOR[0]; 
	temp.XOR[1] = x.XOR[1] ^ y.XOR[1];
	return temp; 
}
void build(int x, int tl, int tr) {
	if (tl == tr) {
		t[x].XOR[s[tl - 1] - '0'] = a[tl];
		t[x].XOR[1 - (s[tl - 1] - '0')] = 0;
		t[x].lazy = 0; 
		return;
	}
	int mid = (tl + tr) / 2; 
	build(2 * x, tl, mid); 
	build(2 * x + 1, mid + 1, tr); 
	t[x] = merge(t[2 * x], t[2 * x + 1]); 
}
void push(int x, int tl, int tr) {
	if (t[x].lazy) {
		swap(t[x].XOR[0], t[x].XOR[1]);
		if (tl != tr) {
			t[2 * x].lazy ^= t[x].lazy; 
			t[2 * x + 1].lazy ^= t[x].lazy;
		}
		t[x].lazy = 0;
	}
}
void update(int x, int tl, int tr, int i, int j) {
	push(x, tl, tr); 
	if (j < tl or i > tr) return; 
	if (i <= tl and tr <= j) {
		t[x].lazy = 1;
		push(x, tl, tr);
		return; 
	}
	int mid = (tl + tr) / 2;
	update(2 * x, tl, mid, i, j);
	update(2 * x + 1, mid + 1, tr, i, j);
	t[x] = merge(t[2 * x], t[2 * x + 1]);
}
node query(int x, int tl, int tr, int i, int j) {
	push(x, tl, tr); 
	if (j < tl or i > tr) { 
		node temp; 
		return temp;
	}  
	if (i <= tl or tr <= j) {
		return t[x];  
	}
	int mid = (tl + tr) / 2;
	return merge(query(2 * x, tl, mid, i, j), query(2 * x + 1, mid + 1, tr, i, j));
}
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> s;
	build(1, 1, n); 
	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp; 
		if (tp == 1) {
			int l, r; cin >> l >> r;
			update(1, 1, n, l, r); 
		} else {
			int x; cin >> x; 
			node res = query(1, 1, n, 1, n); 
			cout << res.XOR[x] << ' ';
		}
	}
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}