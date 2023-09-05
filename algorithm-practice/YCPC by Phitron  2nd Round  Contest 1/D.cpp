#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
const int N = 1e4 + 1;
int n;
ll a[N]; 
int c; 
bool check(ll x) {
    ll curr = a[0];
    int cnt = 1; 
    for (int i = 1; i < n; i++) {
        if (a[i] - curr >= x) {
            curr = a[i];
            cnt++; 
            if (cnt == c) 
                return true; 
        }
    }
    return false;
}
void solve() {
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i - 1]; 
    cin >> c;
    sort(a, a + n); 
    // int mn = 1e9 + 100; 
    // for (int i = 1; i < n; i++) mn = min(mn, a[i] - a[i - 1]);
    ll ans = 0; 
    ll l = 1, r = a[n - 1];
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            ans = max(ans, mid); 
            l = mid + 1;
        } else r = mid;
        // cout << l << ' ' << r << '\n';
    }
    cout << ans << '\n';
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
    cin >> T; 
    while (T--) solve(); 
}