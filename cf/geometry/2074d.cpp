#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	int n, m;
	cin >> n >> m;
	vi x(n), r(n);
	rep(i, 0, n) cin >> x[i];
	rep(i, 0, n) cin >> r[i];
	
	unordered_map<int, ll> mp;
	rep(i, 0, n) {
		rep(j, x[i] - r[i], x[i] + r[i] + 1) {
			int dx = x[i] - j;
			ll y = (ll) sqrt(1ll * r[i] * r[i] - 1ll * dx * dx); 
			mp[j] = max(mp[j], 2 * y + 1);
		}
	}
	
	ll ans = 0;
	for (auto& [x, c]: mp) {
		ans += c;
	}
	cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
