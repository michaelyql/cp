#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == k) {
		int ans = -1;
		for (int i = 2; i <= n; i += 2) {
			if (a[i] != i / 2) {
				ans = i / 2;
				break;
			}
		}
		if (ans == -1) {
			ans = n / 2 + 1;
		}
		cout << ans << endl;
	} else {
		int pos = -1;
		for (int i = 2; i <= n - k + 2; i++) {
			if (a[i] != 1) {
				pos = i;
				break;
			}
		}
		// cout << "pos: " << pos << endl;
		if (pos == -1) {
			int cur = 2;
			for (int i = n - k + 1; i <= n; i += 2) {
				if (a[i] != cur) {
					break;
				}
				cur++;
			}
			cout << cur << endl;
		} else {
			cout << 1 << endl;
		}
	}
	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
