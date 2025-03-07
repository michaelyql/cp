#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> values;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end()); 
	a[0] = min(a[0], b[0] - a[0]);
	for (int i = 1; i < n; i++) {
		// b[x] - a[i] >= a[i - 1]
		// b[x] >= a[i] + a[i - 1]
		auto it = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
		if (it == b.end()) {
			if (a[i] < a[i - 1]) {
				cout << "NO" << endl;
				return;
			}
		} else {
			if (a[i] < a[i - 1]) {
				a[i] = *it - a[i];
			} else {
				a[i] = min(a[i], *it - a[i]);	
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
