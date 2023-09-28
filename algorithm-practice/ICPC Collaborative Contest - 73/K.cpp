#include <bits/stdc++.h>
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define pb push_back
#define ff first
#define ss second
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define all(n) n.begin(),n.end()
#define endl '\n'
#define optimize(); std::ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

ll n,m;
ll dp[15][10005];
ll highpow(ll x){
    if (x < m) return 0; 
    ll cnt = 0; 
    ll ans = 1LL; 
    while (ans < x) {
        ans *= m; 
        if (ans <= x) 
            cnt++; 
    }
    return cnt; 
}

ll rec(ll pow,ll tar){
    ll mpow = 1;
    if (tar < 0) {
        return 0; 
    } 
    if (pow == 0 || tar == 0) {
        return 1;
    }
    ll npow = pow;
    while (npow--) mpow *= m;

    if (dp[pow][tar] != -1) return dp[pow][tar]; 
    ll ans = 0;
    for (ll i = 0; i * mpow <= tar; i++) {
        
        ans += rec(pow - 1, tar - i * mpow); 
    }
    return dp[pow][tar] = ans;
} 


void solve(){
    ll k;
    cin>>k>>m>>n; 
    memset (dp, -1, sizeof dp); 
    // cout << highpow(n) << '\n';
    cout << k << ' ' << rec(highpow(n), n) << '\n';
}

int main(){
    optimize();
    ll tc;  cin>>tc;
    while(tc--) solve();

    return 0;
}