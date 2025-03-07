#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	unordered_set<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (a.find(x) == a.end()) a.insert(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (b.find(x) == b.end()) b.insert(x);
	}
	if (a.size() + b.size() >= 4) cout << "YES" << endl;
	else cout << "NO" << endl;
}	

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
