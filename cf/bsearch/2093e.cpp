#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

bool ok(int x, vi& a, int k) {
	int n = a.size();
	
	vector<bool> mark(n+1, false);
	vector<int> vis;
	int mex = 0;
	int bl = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] < n) {
			mark[a[i]] = true;
			vis.push_back(a[i]);	
		}
		while (mark[mex]) mex++;
		if (mex >= x) {
			mex = 0;
			bl++;
			for (int& y : vis) mark[y] = false;
			vis.clear();
		}
	}
	
	return bl >= k;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	int lo = 0, hi = n;
	
	int ans = 0;
	
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (ok(mid, a, k)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
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
