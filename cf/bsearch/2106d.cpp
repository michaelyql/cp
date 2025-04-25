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

int n, m;

// Can be solved without binary search in O(n)... the only valid answers are in b[i] 

bool ok(int k, vi& a, vi& b, vi& pref, vi& suff) {
	for (int i = 0; i <= n; i++) { // possible insert positions
		int j = pref[i]; 
		if (k >= b[j] && suff[i] >= m - j - 1) {
			return true;
		}
	}	
	return false;
}

void solve() {
	cin >> n >> m;
	vi a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	vi pref(n+1), suff(n+1);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (j < m && a[i] >= b[j]) {
			j++;
		}
		pref[i+1] = j;
	}
	if (pref[n] == m) {
		cout << 0 << endl;
		return;
	}
	int sj = 0;
	
	for (int i = n - 1; i >= 0; i--) {
		if (sj < m && a[i] >= b[m-1-sj]) {
			 sj++;
		}
		suff[i] = sj;
	}
	int lo = 1, hi = *max_element(b.begin(), b.end());
	int ans = -1;
	while (lo <= hi) {
		int k = lo + (hi - lo) / 2;
		if (ok(k, a, b, pref, suff)) {
			ans = k;
			hi = k - 1;
		} else {
			lo = k + 1;
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
