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

void solve() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	ll sum = 0;
	rep(i, 0, n / 2) {
		sum += a[i * 2];
	}
	if (n & 1) sum += a[n - 1];
	vi v1(n/2), v2(n/2);
	rep(i, 0, n/2) {
		v1[i] = a[2*i + 1] - a[2*i];
		if (2*i + 2 < n) v2[i] = a[2*i + 1] - a[2*i + 2];
	}
	ll csum = 0, msum = 0, diff = 0;
	rep(i, 0, n/2) {
		csum += v1[i];
		msum = min(msum, csum);
		diff = max(diff, csum - msum);
	} 
	csum = 0, msum = 0;
	rep(i, 0, n/2) {
		csum += v2[i];
		msum = min(msum, csum);
		diff = max(diff, csum - msum);
	}
	cout << sum + diff << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
