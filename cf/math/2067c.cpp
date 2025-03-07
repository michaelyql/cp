#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	string x;
	cin >> x;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '7') {
			cout << 0 << endl;
			return;
		}
	}
	ll v = stoll(x);
	for (int i = 1; i <= 7; i++) {
		v--;
		string y = to_string(v);
		auto it = find(y.begin(), y.end(), '7');
		if (it != y.end()) {
			cout << i << endl;
			return;
		}
		
		it = find(y.begin(), y.end(), '7' - i);
		if (it != y.end()) {
			cout << i << endl;
			return;
		}
		
	}
	cout << 7 << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
