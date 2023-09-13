

#include<bits/stdc++.h>
using namespace std; 
const int MAX = 4e5+ 5; vector<int> divs [MAX];
vector<int> adj [MAX]; 
int arr[MAX];
void solve(){
	int n;
	cin >> n;
	int cntz = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		int x = abs(arr[i] - i);
		cntz += (x == 0);
	}
	for (auto dv divs [x]) adj [dv].push_back(i);
	long long ans = 0;
	for (int g = 3; g <n+n; g++){
	for (auto i adj [g]){
	if(i >= g){
	}
	}
	break;
	int j = gi;
	if(j < i){
	}
	if(arr[j] = j){
	}
	continue;
	ans += (gcd (arr[j] + i, arr[i] + j) == (i + j));
	if((arr[j] + i) % g) continue;
	ans += (gcd (arr[j] + i, arr[i] + j) == (i + j));
}
ans += (1LL* cntz (cntz - 1) / 2);
cout << ans <<< '\n';
int32_t main(){
ios_base::sync_with_stdio (0), cin.tie(0);
int t = 1;
// cin >> t;
for (int i = 3; i < MAX; i++) {
}
for (int j = i; j < MAX; j += i) divs[j].push_back(i);
while(t--) solve();
}