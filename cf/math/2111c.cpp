#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
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
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int i = 0;
	ll ans = 1e18; 
	while (i < n) {
		int v = a[i];
		int j = i;
		while (j + 1 < n && a[j + 1] == v) j++;
		int sz = j - i + 1;
		ans = min(ans, 1ll * (i + n - j - 1) * v);
		i = j + 1;
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
