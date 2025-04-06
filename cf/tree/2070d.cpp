#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 998244353;

void dfs(int u, int d, vector<vi>& depth, vector<vi>& children) {
	depth[d].push_back(u);
	for (auto v : children[u]) {
		dfs(v, d + 1, depth, children);
	}
}

void solve() {
	int n;
	cin >> n;
	vi p(n+1);
	vector<vi> children(n+1);
	rep(i, 2, n + 1) {
		cin >> p[i];
		children[p[i]].push_back(i);
	}
	vector<vi> depth(n);
	vi dp(n+1);
	dfs(1, 0, depth, children);
	ll prev_sum = 0;
	for (int i = n - 1; i > 0; i--) {
		ll new_sum = 0;
		for (int u : depth[i]) {
			ll child_sum = 0;
			for (int v : children[u]) {
				child_sum = (child_sum % MOD + dp[v] % MOD) % MOD;
			}
			dp[u] = (((prev_sum - child_sum) + MOD) % MOD + 1) % MOD;
			new_sum = (new_sum % MOD + dp[u] % MOD) % MOD;
		}
		prev_sum = new_sum % MOD;
	}
	ll ans = 1;
	for (int v : children[1]) {
		ans = (ans % MOD + dp[v] % MOD) % MOD;
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


/*
           total 
   1       - 8
 2   5     - 3/4
3 4  7     - 2/1/2
  6        - 1
*/

/*
1       - 4
2 4     - 1/2
3       - 1

*/


