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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;

void solve() {
	int n; 
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int ans = 1005;
	rep(i, 0, n) {
		int rmin = 1e9, rmax = -1e9;
		rep(j, i + 1, n) {
			rmin = min(rmin, a[j]);
			rmax = max(rmax, a[j]);
			if (rmin <= a[i] + 1 && rmax >= a[i] - 1 && rmin <= rmax) {
				ans = min(ans, j - i - 1);
				break;
			}
		}
		rmin = 1e9, rmax = -1e9;
		for (int j = i - 1; j >= 0; j--) {
			rmin = min(rmin, a[j]);
			rmax = max(rmax, a[j]);
			if (rmin <= a[i] + 1 && rmax >= a[i] - 1 && rmin <= rmax) {
				ans = min(ans, i - j - 1);
				break;
			}
		}
	}
	cout << (ans == 1005 ? -1 : ans) << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
