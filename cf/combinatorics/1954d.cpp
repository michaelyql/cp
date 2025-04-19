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
 
const int MOD = 998244353;
 
void solve() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int sum = accumulate(a.begin(), a.end(), 0);
	int mn = *min_element(a.begin(), a.end());
	vector<ll> dp(sum + 1, 0);
	dp[0] = 1;
	for (auto& x : a) {
		for (int s = sum - x; s >= 0; s--) {
			dp[s + x] = (dp[s + x] + dp[s]) % MOD;
		}
	}
	ll ans = 0;
	for (int s = 0; s <= sum; s++) {
		ans = (ans + ((s + 1) / 2) % MOD * dp[s] % MOD) % MOD;
	}
	for (auto& x : a) {
		for (int i = 0; i < x; i++) {
			ans = (ans + (x - (x + i + 1) / 2) * dp[i] % MOD) % MOD;
		}
	}
	cout << ans << endl;
} 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	solve();
}
