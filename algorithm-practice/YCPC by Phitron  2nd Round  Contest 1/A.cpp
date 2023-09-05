#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

void solve() {
    ll a, b;
    cin >> a >> b; 
    cout << ((a % 100) * (b % 100) % 100) << '\n';    
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    cin >> T; 
    while (T--) solve(); 
}