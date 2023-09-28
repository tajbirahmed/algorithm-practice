#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 2e5 + 1; 
ll fact[N]; 
const ll mod = 998244353LL;
void pre () {
	fact[0] = fact[1] = 1; 
	for (int i = 2; i < N; i++) {
		fact[i] = i * fact[i - 1] % mod; 
	}
}

void solve() {
	string s; cin >> s; 
	ll cnt = 0; 
	for (int i = 0; i < s.size(); i++) {
		if (i and s[i] == s[i - 1]) ++cnt; 
	}
	vector <ll> v;
	ll cnt1 = 1;  
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			cnt1++; 			
		} else {
			v.push_back(cnt1); 
			cnt1 = 1; 
		}
	}
	if (cnt1 != 1) v.push_back(cnt1); 
	ll ans = 1LL;
	for (auto i : v) { 
		ans = (ans % mod) * (i % mod) % mod; 
	}
	cout << cnt << ' ' << (ans * fact[cnt]) % mod << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}