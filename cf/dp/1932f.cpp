#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> endpoints(n + 1);
	vector<int> cnt(n + 1), change(n + 2);
	rep(i, 0, m) {
		int l, r;
		cin >> l >> r;
		endpoints[l].push_back(r); 
		change[l]++;
		change[r + 1]--; 
	}
	int active = 0; // number of active intervals
	rep(i, 1, n + 1) {
		active += change[i]; 
		cnt[i] = active;
	}
	vector<int> dp(n + 2); // dp[i] : best answer if you use points from 1 up to i-1
	int max_r = 0;
	rep(i, 1, n + 1) {
		for (int& r : endpoints[i]) max_r = max(max_r, r); 
		dp[i + 1] = max(dp[i + 1], dp[i]); // if don't take point i
		dp[max_r + 1] = max(dp[max_r + 1], dp[i] + cnt[i]); // if take point i
	}
	cout << dp[n + 1] << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
