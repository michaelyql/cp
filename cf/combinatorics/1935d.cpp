#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define debug

#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
	int n, c;
	cin >> n >> c;
	unordered_set<int> s;
	ll even = 0, odd = 0;
	rep(i, 0, n) {
		int x;
		cin >> x;
		s.insert(x);
		if (x & 1) odd++;
		else even++;
	}
	// no. of pairs such that x+y is in s
	ll size1 = 0;
	for (auto& x : s) {
		if (x > 2 * c) continue;
		
		if (x <= c) {
			size1 += (x + 2) / 2;
		} else {
			size1 += (2 * c - x) / 2 + 1;
		}
	}
	// no. of pairs such that y-x is in s
	ll size2 = 0;
	for (auto& x : s) {
		if (x > c) continue;
		size2 += c - x + 1;
	}
	ll all_pairs = 1ll * (c + 1) * (c + 2) / 2;
	// overlap where x+y, y-x both in s
	cout << all_pairs - size1 - size2 + (even + 1) * even / 2 + (odd + 1) * odd / 2;
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
