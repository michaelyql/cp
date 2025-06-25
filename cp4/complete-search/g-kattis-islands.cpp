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
	int k;
	cin >> k;
	vi a(12);
	rep(i, 0, 12) cin >> a[i];
	int ans = 0;
	rep(i, 1, 11) {
		int mn = a[i];
		rep(j, i, 11) {
			mn = min(mn, a[j]);
			if (mn > max(a[i - 1], a[j + 1])) {
				ans++;
			}
		}
	}
	cout << k << " " << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
