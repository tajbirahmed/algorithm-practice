#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
  int n; 
  cin >> n; 
  string s, t;
  cin >> s >> t;
  set <int> st;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
        if (st.find(i - 1) == st.end()) ++cnt; 
        st.insert(i); 
    }
  }
  cout << cnt << '\n';
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    // cin >> T; 
    while (T--) solve(); 
}