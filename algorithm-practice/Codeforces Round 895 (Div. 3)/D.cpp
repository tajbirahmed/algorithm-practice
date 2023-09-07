#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	ll lcm = (x * y) / __gcd(x, y); 
	ll k = n / lcm;
	ll x_div = n / x - k; 
	ll y_div = n / y - k; 
	ll add = n * (n + 1) / 2 - (n - x_div) * (n - x_div + 1) / 2;
	ll sub = y_div * (y_div + 1) / 2;
	cout << add - sub << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}