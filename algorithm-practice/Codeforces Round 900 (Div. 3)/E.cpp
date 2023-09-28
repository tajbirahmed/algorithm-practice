#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
const int N = 2e5 + 10; 
long long a[N], total[4 * N];
void build(int x, int l, int r) {
	if (l == r) {
		total[x] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	total[x] = total[2 * x] & total[2 * x + 1];
}

long long query(int x, int l, int r, int i, int j) {
	if (l >= i and r <= j)
		return total[x]; 
	if (r < i or l > j) return LLONG_MAX; 
	int mid = (l + r) / 2; 
	return query(2 * x, l, mid, i, j) & query(2 * x + 1, mid + 1, r, i, j);
}

void solve() {
	int n, m;
	cin >> n; 
	for (int i = 0; i < n; i += 1) {
		cin >> a[i + 1]; 
	}
	cin >> m; 
	build(1, 1, n);
	while (m--) {
		int l, x; cin >> l >> x; 
		int r = n; 
		int tmpl = l;
		while (tmpl <= r) {
			int mid = (tmpl + r) / 2;
			int q = query	(1, 1, n, l, tmpl) & query	(1, 1, n, tmpl, mid);
			if (q < x) {
					r = mid - 1; 
			} else {
				tmpl = mid + 1;
			}
		}
		// cout << l << ' ' << r << '\n';
		if (r >= l and query (1, 1, n, l, r) >= x) {
			cout << r << ' ';
		} else cout << "-1 ";
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