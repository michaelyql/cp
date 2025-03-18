#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int blk = 1;
	rep(i, 1, n) {
		if (s[i] != s[i-1]) blk++;
	}
	if (b >= 0) {
		cout << a * n + b * n << endl;
	} else {
		cout << a * n + b * (blk / 2 + 1) << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
