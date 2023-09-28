#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
  int n; cin >> n; 
  ll a[n]; 
  for (int i = 0; i < n; i++) cin >> a[i]; 
  int i = 2; 
  while (i < n) {
    if (3 * a[i] % (a[i - 1] + a[i - 2]) == 0) cout << 1 << ' ';
    i++;
  } 
}
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1; 
  // cin >> T; 
  while (T--) solve(); 
}