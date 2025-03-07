#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll ans = accumulate(a.begin(), a.end(), 0ll);
	for (int i = 1; i < n; i++) {
		ll sum = 0;
		for (int j = n - 1; j >= i; j--) {
			a[j] -= a[j - 1];
			sum += a[j];
		}
		ans = max(max(ans, sum), -sum);
	}
	cout << ans << endl;		
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
