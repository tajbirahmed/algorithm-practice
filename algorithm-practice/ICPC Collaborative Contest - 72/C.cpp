#include "bits/stdc++.h"
using namespace std; 
using ll = long long;
ll fact[20]; 
void pre() {
	fact[0] = fact[1] = 1; 
	for (ll i = 2; i < 20; i++) {
		fact[i] = i * fact[i - 1]; 
		// cout << fact[i] << '\n';
	}
} 
void solve() {
	string s; int n; 
	cin >> s >> n; 
	set <char> st;
	for(int i = 0; i < s.size(); i++) {
		st.insert(s[i]); 
	}
	ll ans = 0LL;
	int k = 1;
	for (auto c : st) {
		ll r = n - 1;
		ll N = 'r' - c;
		if (N - r < 0) continue; 
		ans += fact[N] / (fact[r] * fact[N - r]); 
	}
	ll N = st.size();
	ll r = n;
	if (N - r >= 0){
		ans += fact[N] / fact[N - r]; 
		ans -= fact[N] / (fact[r] * fact[N - r]);
	}
	cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	pre();  
	cin >> T; 
	while (T--) solve(); 
}