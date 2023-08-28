#include "bits/stdc++.h"
using namespace std; 
using ll = long long; 

bool cmp(pair<double, double> a, pair<double, double> b) {
	return a.second < b.second;
} 

int main () {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int n, d; 
  	int t = 1;
  	while (1) {
  		cin >> n >> d;
		if (n == 0 and d == 0) break;
		cout << "Case " << t << ": ";
		vector<pair <int, int>> p;
		bool f = 1; 
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			p.push_back({x, y}); 
			if (y > d) {
				f = 0;
			}
		}
		if (!f) {
			cout << "-1\n";
			continue;
		}
		vector <pair<double, double>> rng; 
		for (int i = 0; i < n; i++) {
			rng.push_back({
				p[i].first - sqrt(d * d - p[i].second * p[i].second), 
				p[i].first + sqrt(d * d - p[i].second * p[i].second)
			});
		}
		sort (rng.begin(), rng.end(), cmp);
		double mn = INT_MIN;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mn < rng[i].first) {
				cnt++;
				mn = rng[i].second;
			}
		}
		cout << cnt << '\n';
		t++;
  	} 
}