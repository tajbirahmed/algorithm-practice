#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n; 
string s; 
void solve() {
	cin >> n >> s;
	int l = 0, r = n - 1; 
	int cnt = 0, zerocnt = 0; 
	while (l < r) {
		if (s[l] != s[r]) ++cnt; 
		l++;
		r--; 
	}
	string t = "";
	int x = cnt; 
	while (cnt--) t += "0"; 
	if (n & 1) {
		int p = n - 2 * x + 1;
		while (p--) t += "1"; 
		while (x--) t += "0";
	} else {
		int p = n - 2 * x + 1;

		while (p--) { 
			if (p % 2 == 0) t += "1"; 
			else t += "0";
		}
		while (x--) t += "0";
	}
	cout << t << '\n';
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}