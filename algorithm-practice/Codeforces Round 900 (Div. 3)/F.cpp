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
	if (r < i or l > j) return 0; 
	if (l >= i and r <= j)
		return total[x]; 
	int mid = (l + r) / 2; 
	return query(2 * x, l, mid, i, j) & query(2 * x + 1, mid + 1, r, i, j);
}

void solve() {
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	 
	build(1, 1, n);
	int q; cin >> q; 
	while (q--) {
		int l, k; cin >> l >> k; 
		if (query(1, 1, n, l, l) < k) {
			int r = n; 
			while (l <= r) {
				int mid = (l + r) / 2; 
				if (query(1, 1, n, l, mid) >= k) {
					r = mid - 1; 
				} else break; 
			}
			cout << r << ' ';
		
		} else {
			cout << "-1 ";
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