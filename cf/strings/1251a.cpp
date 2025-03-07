#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	string s;
	cin >> s;
	if (s.size() == 1) {
		cout << s[0] << endl;
		return;
	}
	vector<bool> ok(26, false);
	for (int i = 0; i < s.size(); ) {
		char c = s[i];
		int j = i + 1;
		int cnt = 1;
		while (j < s.size() && s[j] == c) {
			j++;
			cnt++;
		}
		if (cnt & 1) ok[c - 'a'] = true;
		i = j;
	}
	for (int i = 0; i < 26; i++) {
		if (ok[i]) cout << (char) (i + 'a');
	}
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
