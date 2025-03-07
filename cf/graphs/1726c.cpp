#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 1;
	for (int i = 1; i < 2 * n - 1; i++) {
		if (s[i] == '(') {
			if (s[i - 1] == '(') {
				ans++;
			}
		} 
	}
	cout << ans << endl;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) solve();
}
