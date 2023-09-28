#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 
int n, m; 
const int N = 1e3 + 5; 
int a[N][N];
bool vis[N][N], vishash[N][N];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx1[] = {1, 0, -1, 0}; 
int dy1[] = {0, 1, 0, -1};
int island = 0; 
string s[N];
bool inRange(int i, int j) {
	return i >= 0 and j >= 0 and i <= n + 1 and j <= m + 1;
}
bool inRange1(int i, int j) {
	return i >= 0 and j >= 0 and i < n and j < m;
}
void dfs(int u, int v) {
	vis[u][v] = 1; 
	for (int i = 0; i < 8; i++) {
		int nx = u + dx[i]; 
		int ny = v + dy[i]; 
		if (inRange(nx, ny) and !vis[nx][ny] and a[nx][ny]) {
			dfs(nx, ny);
		}
	}
} 
void dfshash(int u, int v) {
	vishash[u][v] = 1; 
	for (int i = 0; i < 4; i++) {
		int nx = u + dx1[i]; 
		int ny = v + dy1[i]; 
		if (inRange1(nx, ny) and !vishash[nx][ny] and s[nx][ny] == '#') {
			dfshash(nx, ny);
		}
	}
}
void dfswater(int u, int v) {
	vis[u][v] = 1; 
	for (int i = 0; i < 8; i++) {
		int nx = u + dx[i]; 
		int ny = v + dy[i]; 
		if (inRange(nx, ny) and !vis[nx][ny] and a[nx][ny]) {
			dfswater(nx, ny);
		}
	}
}
void solve() {
	cin >> n >> m; 
		for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			a[i][j] = 1;
		}
	} 
	for (int i = 0; i < n; i++) {
		cin >> s[i]; 
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') {
				a[i + 1][j + 1] = 1;
			} else {
				a[i + 1][j + 1] = 0;
			}
		}
	}
	memset(vis, false, sizeof (vis)); 
	memset(vishash, false, sizeof (vishash)); 

	dfs(0, 0);
	island = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vishash[i][j] and s[i][j] == '#') {
				dfshash(i, j);
				++island;
			}
		}
	}
	int closed_water = 0; 
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (!vis[i][j] and a[i][j]) {
				dfswater(i, j);
				++closed_water;
				// cout << i << ' ' << j << '\n';
			}
		}
	}
	
	cout << island << ' ' << closed_water << '\n';
	if (island and closed_water < island) cout << "Yes\n"; 
	else cout << "No\n";
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1; 
	cin >> T; 
	while (T--) solve(); 
}