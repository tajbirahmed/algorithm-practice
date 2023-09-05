#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e5 + 1;
ll dp[N];
ll a[N]; 
ll count(ll x) {
    if (x <= 0) return 0; 
    if (dp[x] != -1) return dp[x];
    ll ans = count(x - 1); 
    if (a[x] != -1) {
        ans = max(ans, a[x] + count(x - 2));
    }
    return dp[x] = ans;
}
void solve() {
    int n; cin >> n; 
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << count(n) << '\n';
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    // cin >> T; 
    while (T--) solve(); 
}