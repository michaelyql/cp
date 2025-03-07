#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int diff = abs(n - m);
	
	if (diff > k) {
		cout << -1 << endl;
		return;
	}

	string s;
	ostringstream oss;
	if (n > m) {
		if (k > n) {
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < k; i++) oss << "0";
		int remaining = min(n - k, m);
		for (int i = 0; i < remaining; i++) oss << "10";
		for (int i = 0; i < m - remaining; i++) oss << "1";
		s = oss.str();
	} else {
		if (k > m) {
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < k; i++) oss << "1";
		int remaining = min(m - k, n);
		ostringstream rem, zeroes;
		
		for (int i = 0; i < remaining; i++) rem << "10";
		for (int i = 0; i < n - remaining; i++) zeroes << "0";
		s = zeroes.str() + rem.str() + oss.str();
	}
	cout << s << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
