#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

const ll mod = 1e9 + 7;

void solve() {
   ll n; 
   cin >> n; 
   ll b[n]; 
   for (int i = 0; i < n; i++) {
      cin >> b[i];
   }  
   bool f = 1;
   ll curr = 1LL; 
   for (int i = 0; i < n; i++) {
      curr = (curr * 2 - b[i] % mod + mod) % mod; 
      if ()
   }
   if (f) 
      cout << curr % mod << '\n';
   else 
      cout << "error\n";
}
int main () {
   ios_base::sync_with_stdio(0);
     cin.tie(0);
     int T = 1; 
     // cin >> T; 
     while (T--) solve(); 
}