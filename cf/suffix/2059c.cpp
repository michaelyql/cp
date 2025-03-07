#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int a[N][N];
int suffix[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(suffix, 0, n * 4);
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] != 1) break;
			suffix[i]++;
		}
	}
	multiset<int> ms;
	for (int i = 0; i < n; i++) ms.insert(suffix[i]);
	int ans = 1;
	for (auto it = ms.begin(); it != ms.end(); it++) {
		if (*it >= ans) ans++;
	}
	cout << min(ans, n) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
