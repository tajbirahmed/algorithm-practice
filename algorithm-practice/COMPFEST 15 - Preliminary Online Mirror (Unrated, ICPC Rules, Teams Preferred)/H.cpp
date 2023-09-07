#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
ll n, k; 
const int N = 2e5 + 1;
const ll mod = 998244353; 
ll fact[N], rev_fact[N], G[N], F[N];
ll mul(ll a, ll b) { // a * b % mod
	return __int128(a) * b % mod;
}
ll power(ll a, ll b) { // a^b % mod
	ll ans = 1 % mod;
	while (b) {
	if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}
void funcG(ll e) {
	ll x = fact[n - e + 1];  
	ll p = power(n - e + 1, k - n + e); 
	G[e] = ((x % mod) * (p % mod)) % mod; 
}
void pre() {
	fact[1] = 1;
	for (ll i = 2; i < N; i++) {
		fact[i] = ((i % mod) * (fact[i - 1] % mod)) % mod;
	}
	rev_fact[N - 1] = (N - 1) % mod; 
	for (ll i = N - 2; i >= 1; i--) {
		rev_fact[i] = ((i % mod) * (rev_fact[i + 1] % mod)) % mod;
	}
}
void solve() {
	cin >> n >> k; 
	for (ll i = 1; i <= n; i++) {
		funcG(i);
	}
	F[n] = G[n];
	for (int i = 1; i < n; i++) {
		F[i] = G[i] - G[i + 1];
	}
	ll ans = 0; 
	for (int i = 1; i <= n; i++) {
		ans = ((ans % mod) + (F[i] * rev_fact[i + 1]) % mod) % mod;
	}
	cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	pre(); 
	// cin >> T; 
	while (T--) solve(); 
}