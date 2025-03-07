#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> values;
	for (int i = 0; i < n; i++) {
		ll psum = 0;
		ll overall_sum = 0;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			psum += x;
			overall_sum += psum;
		}
		values.push_back({psum, overall_sum - psum});
	}
	sort(values.begin(), values.end(), [](const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
		return p1.first > p2.first;
	});
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (values[i].first) * (1 + (n - i - 1) * m);
		ans += values[i].second;
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
