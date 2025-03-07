#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int p_cnt = 0;
	int s_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'p') {
			p_cnt++;
		} else if (s[i] == 's') {
			s_cnt++;
			if (p_cnt > 0) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	if (p_cnt == 0) {
		// no 'p' at all
		cout << "YES" << endl;
		return;
	}
	if (s_cnt == 0) {
		// no 's' at all
		cout << "YES" << endl;
		return;
	}
	// all 's' that appear come before any 'p'
	if (p_cnt == 1 && s_cnt == 1) {
		if (s[0] == 's' || s[n - 1] == 'p') {
			cout << "YES" << endl;
			return;
		}
		// ...s...p...
		cout << "NO" << endl;
	} else {
		if (p_cnt == 1) {
			if (s[n - 1] == 'p') cout << "YES" << endl;
			else cout << "NO" << endl;
			// ssp.
		} else if (s_cnt == 1) {
			if (s[0] == 's') cout << "YES" << endl;
			else cout << "NO" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
