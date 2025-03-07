#include <bits/stdc++.h>
using namespace std;

const int M = 262144 + 5;
int A[M];

pair<int, int> check(int l, int r) {
	if (l + 1 == r) {
		if (A[r] % 2 == 0) {
			if (A[l] + 1 == A[r]) return {0, A[r]};
		} else {
			if (A[l] - 1 == A[r]) return {1, A[l]};
		}
		return {-1, -1};
	}
	int mid = l + (r - l) / 2;
	pair<int, int> a = check(l, mid);
	pair<int, int> b = check(mid + 1, r);
	if (a.first == -1 || b.first == -1) return {-1, -1};
	int c = min(a.second, b.second);
	int d = max(a.second, b.second);
	
	int sz = r - l + 1;
	if (c != d - sz / 2) return {-1, -1};
	
	
	return {a.first + b.first + (a.second > b.second), max(a.second, b.second)};
}

void solve() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) cin >> A[i];
	if (m == 1) cout << 0 << endl;
	else cout << check(0, m - 1).first << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
