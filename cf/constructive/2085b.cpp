#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	cin >> n;
	vi a(n);
	
	bool hasZero = false;
	rep(i, 0, n) { 
		cin >> a[i];
		if (a[i] == 0) hasZero = true;
	}
	
	if (!hasZero) {
		cout << 1 << endl;
		cout << 1 << " " << n << endl;
		return;
	}
	
	vector<pii> b;
	int j = 0;
	int i = 0;
	for (; i < n ; i += 2) {
		if (i < n - 1 && (a[i] == 0 || a[i + 1] == 0)) {
			b.push_back({ i + 1 - j, i + 2 - j });
			j++;
		}
		if (i == n - 1) break;
	}
	if (i == n - 1 && a[i] == 0) {
		b.push_back({ i - j, i - j + 1 });
		j++;
	}
	int k = n - j;
	cout << b.size() + 1 << endl;
	for (pii& p : b) {
		cout << p.first << " " << p.second << endl;
	}
	cout << 1 << " " << k << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
