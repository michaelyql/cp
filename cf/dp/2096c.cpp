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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

const ll INF = 1e18;

ll check(vvi& grid, vi& cost, int& n) {
	vvll dp(n, vll(n, INF));
	dp[0][0] = 0;
	dp[0][1] = cost[0];
	// for the second row onwards
	rep(i, 1, n) {
		// for each of the combinations 00, 01, 10, 11
		rep(x, 0, 2) {
			rep(y, 0, 2) {
				// for each column, check vertical condition is met
				bool ok = true;
				rep(j, 0, n) {
					ok &= grid[i - 1][j] + y != grid[i][j] + x;
				}
				if (ok) {
					if (x == 0) dp[i][x] = min(dp[i][x], dp[i - 1][y]);
					else dp[i][x] = min(dp[i][x], dp[i - 1][y] + cost[i]);
				}
			}
		}
	}
	return min(dp[n - 1][0], dp[n - 1][1]);
}

void transpose(vvi& grid, int& n) {
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			swap(grid[i][j], grid[j][i]);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vvi grid(n, vi(n));
	rep(i, 0, n) rep(j, 0, n) cin >> grid[i][j];
	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	
	ll ans1 = check(grid, a, n);
	transpose(grid, n);
	ll ans2 = check(grid, b, n);
	ll ans = ans1 + ans2;
	if (ans >= INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
