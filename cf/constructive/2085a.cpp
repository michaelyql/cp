#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string p = s;
	reverse(p.begin(), p.end());
	if (s < p) {
		cout << "YES" << endl;
		return;
	}
	if (k == 0) {
		cout << "NO" << endl;
		return;
	}
	vector<int> cnt(26, 0);
	rep(i, 0, n) {
		cnt[s[i] - 'a']++;
	}
	int unique = 0;
	rep(i, 0, 26) {
		if (cnt[i]) unique++;
	}
	if (unique > 1) cout << "YES" << endl;
	else cout << "NO" << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
