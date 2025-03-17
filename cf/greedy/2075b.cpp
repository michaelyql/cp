#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	int mx = 0, sec_mx = 0;
	rep(i, 0, n) {
		cin >> a[i];
		if (a[i] > mx) {
			sec_mx = mx;
			mx = a[i];
		} else if (a[i] > sec_mx) {
			sec_mx = a[i];	
		}
	}
	if (k == 1) {
		if (a[0] != mx && a[n - 1] != mx) {
			cout << 1ll * mx + max(a[0], a[n - 1]) << endl;
		} else {
			int second_mx = 0;
			cout << 1ll * mx + sec_mx << endl;
		} 
		return;
	}
	
	sort(a.rbegin(), a.rend());
	ll ans = accumulate(a.begin(), a.begin() + k + 1, 0ll);
	cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
