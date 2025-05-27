#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

ll f(int a, int b, int c, vi& x, vi& y) {
	bool adj = false;
	for (int i = 0; i < 4; i++) {
		int nx = x[b] + dx[i];
		int ny = y[b] + dy[i];
		
		if (nx == x[c] && ny == y[c]) adj = true;
	}
	db(adj)
	
	if (adj) return 3ll;
	return 1ll * (abs(x[b] - x[c]) + 1) * (abs(y[b] - y[c]) + 1);
}

void solve() {
	bp(---)
	int n;
	cin >> n;
	vi x(n), y(n);
	multiset<int> sx, sy;
	rep(i, 0, n) {
		cin >> x[i] >> y[i];
		sx.insert(x[i]);
		sy.insert(y[i]);
	}
	if (n <= 2) {
		cout << n << endl;
		return;
	}
	
	if (n == 3) {
		ll a = f(0, 1, 2, x, y);
		ll b = f(1, 0, 2, x, y);
		ll c = f(2, 0, 1, x, y);
		cout << min(a, min(b, c)) << endl;
		return;
	}
	
	const ll INF = 1e18 + 5;
	ll ans = INF;
	rep(i, 0, n) {
		sx.erase(sx.find(x[i]));
		sy.erase(sy.find(y[i]));
		
		int w = *sx.rbegin() - *sx.begin() + 1;
		int h = *sy.rbegin() - *sy.begin() + 1;
		
		db(w)
		db(h)
		db(1ll * w * h)
		
		if (1ll * w * h == (ll) (n - 1)) {
			ans = min(ans, 1ll * w * h + min(w, h));
		} else {
			ans = min(ans, 1ll * w * h);	
		}
		
		sx.insert(x[i]);
		sy.insert(y[i]);
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
