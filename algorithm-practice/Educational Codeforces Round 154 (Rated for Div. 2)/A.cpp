#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
	string s; 
	cin >> s; 
	if (s[0] == '1' || s[0] == '2' || s[0] == '4' || s[0] == '5' || s[0] == '7' || s[0] == '8') cout << s[0] << 3 << '\n'; 
	else if (s[0] != '9')cout << s[0] << 1 << '\n';
	else cout << s[0] << 7 << '\n'; 
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}