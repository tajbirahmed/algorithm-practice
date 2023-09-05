#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
void solve() {
    int n; cin >> n;
    int k = n + 10;
    string s = ""; 
    for (int i = 1; i <= k; i += 2)    {
        for (int sp = ((k - i) / 2); sp; sp--) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) cout << "*";
        cout << '\n';
    }
    for (int i = 1; i <= 5; i++) {
        for (int sp = 1; sp <= 5; sp++) cout << " "; 
        for (int j = 1; j <= n; j++) cout << "*";
        cout << '\n';
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    // cin >> T; 
    while (T--) solve(); 
}