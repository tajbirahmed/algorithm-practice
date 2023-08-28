#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
	int n, l;
	cin >> n >> l;
	string s; cin >> s;
	
	if (l & 1) {
		string od = "", ev = "";
		for (int i = 0; i < n; i++) {
			int k = i + 1; 
			if (k & 1) {
				od += s[i]; 
			} else ev += s[i]; 
		}
		int k = 0;
		sort(ev.begin(), ev.end()); 
		sort(od.begin(), od.end());
		while (k < ev.size() and k < od.size()) {
			cout << od[k]  << ev[k];
			k++;
		}

		while (k < od.size()) {
			cout << od[k];
			k++;
		}
		while (k < ev.size()) {
			cout << ev[k];
			k++; 
		}
		cout << '\n';
	} else {
		sort(s.begin(), s.end()); 
		cout << s << '\n';
	}
}
int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int T = 1; 
  	cin >> T; 
  	while (T--) solve(); 
}