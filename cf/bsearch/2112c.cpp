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
	sort(all(a));
	ll ans = 0;
	for (int i = n - 1; i >= 2; i--) {
		for (int j = i - 1; j >= 1; j--) {
			if (a[n - 1] > a[i] * 2) {
				auto it = upper_bound(a.begin(), a.begin() + j, a[n - 1] - a[j] - a[i]);
				if (it <= a.begin() + j) {
					ans += max(0ll, (ll) (a.begin() + j - it));
				}
			} else {
				auto it = upper_bound(a.begin(), a.begin() + j, a[i] - a[j]);
				if (it <= a.begin() + j) {
					ans += max(0ll, (ll) (a.begin() + j - it));
				}
			}
		}
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
