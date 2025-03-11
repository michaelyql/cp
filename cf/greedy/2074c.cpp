#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int x;
	cin >> x;
	
	// y ^ x if no overlap = y + x, then triangle is not degenerate since y + x !> y ^ x
	
	if (__builtin_popcount(x) == 1 || x == 3) {
		cout << -1 << endl;
		return;
	}
	
	int k = __builtin_popcount(x);
	int p = __builtin_clz(x);
	
	if (k + p != 32) {
		cout << (1 << (31 - __builtin_clz(x))) - 1 << endl;
	} else {
		cout << -1 << endl;	
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
