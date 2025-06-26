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

int main() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int l, r;
	cin >> l >> r;
	sort(all(a));
	int max_dist = 0, ans;
	const int inf = 1e9;

	// check all midpoints between two distinct integers
	for (int i = 0; i < n - 1; i++) {
		int mid = (a[i + 1] + a[i]) / 2;
		for (int d = -1; d <= 1; d++) {
			int x = mid + d;
			if ((x & 1) && l <= x && x <= r) {
				int dist = min(abs(x - a[i]), abs(a[i + 1] - x));
				if (dist > max_dist) {
					max_dist = dist;
					ans = x;
				}
			}
		}
	}

	// check boundaries of valid range 
	for (int d = -1; d <= 1; d++) {
		int dist = inf;
		int L = l + d;
		for (int i = 0; i < n; i++) dist = min(dist, abs(a[i] - L));
		if ((L & 1) && l <= L && L <= r && dist > max_dist) {
			max_dist = dist;
			ans = L;
		}
		dist = inf;
		int R = r + d;
		for (int i = 0; i < n; i++) dist = min(dist, abs(a[i] - R));
		if ((R & 1) && l <= R && R <= r && dist > max_dist) {
			max_dist = dist;
			ans = R;
		}
	}
	cout << ans << endl;
}
