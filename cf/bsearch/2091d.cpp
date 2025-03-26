#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int n, m, k;

bool ok(int x) {
	int bench = m / (x + 1);
	int leftover = m % (x + 1);
	ll s = 1ll * bench * x;
	s += leftover;
	if (s * n >= k) return true;
	else return false;
}

void solve() {
	cin >> n >> m >> k;
	// if (1ll * k > 1ll * n * (m - 1)) {
	// 	cout << m << endl;
	// 	return;
	// }
	int lo = 1, hi = m;
	int ans = hi;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (ok(mid)) {
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
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
