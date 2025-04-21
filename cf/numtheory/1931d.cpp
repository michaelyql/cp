#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define debug
 
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

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	ll ans = 0;
	map<pii, int> mp;
	rep(i, 0, n) {
		int xx = a[i] % x;
		int yy = a[i] % y;
		ans += mp[{(x - xx) % x, yy }];
		mp[{xx, yy}]++;
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
