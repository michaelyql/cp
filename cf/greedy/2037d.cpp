#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	int n, m, l;
	cin >> n >> m >> l;
	vector<pii> intervals;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		intervals.push_back({l, r});
	}
	vector<pii> power;
	for (int i = 0; i < m; i++) {
		int x, v;
		cin >> x >> v;
		power.push_back({x, v});
	}
	int i = 0, j = 0;
	priority_queue<int> pq;
	int used = 0;
	ll total_power = 1;
	while (i < n) {
		auto itv = intervals[i];
		while (j < m && power[j].first < itv.first) {
			pq.push(power[j].second);
			j++;
		}
		int jump = intervals[i].second - intervals[i].first + 2;
		while (total_power < jump && !pq.empty()) {
			total_power += pq.top();
			pq.pop();
			used++;
		}
		if (total_power < jump) {
			cout << -1 << endl;
			return;
		}
		i++; 
	}
	cout << used << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
