#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	ll ones = 0;
	ll twos = 0;
	ll threes = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			ones++;
		} else if (a[i] == 2) {
			// all subsequences with 2 before current 2 (e.g. 1, 2, 2, 2, ..., 2)
			// plus all subsequences with current 2 as the only 2 (i.e. 1, 2)
			twos = (twos * 2 % MOD + ones) % MOD; 
		} else {
			// append current 3 behind all valid subsequences so far of the form "12+"
			threes = (threes + twos) % MOD;
		}
	}
	cout << threes << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
