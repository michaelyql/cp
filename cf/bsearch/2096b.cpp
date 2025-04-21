#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
// #define debug
 
#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

bool ok(ll x, vi &l, vi&r, int& n, int& k, vi& mn, ll& mx) {
	ll cnt = mx;
	int col = 0;

	for (int i = 0; i < n; i++) {
		if (col == k - 1) {
			cnt++;
			break;
		} else {
			cnt += mn[i];
			col++;	
		}
	}
  db(cnt)
  db(x)
	return cnt <= x;
}

void solve() {
	bp(-------tc start----)
	int n, k;
	cin >> n >> k;
	vi l(n), r(n);
	rep(i, 0, n) cin >> l[i];
	rep(i, 0, n) cin >> r[i];
	
	vector<int> mn;
	rep(i, 0, n) mn.push_back(min(l[i], r[i]));
	sort(mn.begin(), mn.end(), greater<int>());
	
	ll lo = 0;
  rep(i, 0, n) lo += max(l[i], r[i]);
  ll mx = lo;
  db(mx)
  lo++;

	ll hi = accumulate(l.begin(), l.end(), 0ll) + accumulate(r.begin(), r.end(), 0ll);
	ll ans = 0;
	while (lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		bp(----)
		db(mid)
		db(lo)
		db(hi)
		if (ok(mid, l, r, n, k, mn, mx)) {
			ans = mid;
			hi = mid - 1;
			bp(ok)
		} else {
			lo = mid + 1;
			bp(not ok)
		}
	}
	cout  << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
