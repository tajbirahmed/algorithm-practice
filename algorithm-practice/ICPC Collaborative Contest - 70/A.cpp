#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	ll x, y; 
	while (1){
		cin >> x >> y; 
		if (x == 0 and y ==0 )
			break;
		if (x + y == 13) {
			cout << "Never speak again.\n";
			continue;
		}	
		if (x > y) {
			cout << "To the convention.\n"; 
		} else if (x < y) {
			cout << "Left beehind.\n"; 
		} else {
			cout << "Undecided.\n"; 
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