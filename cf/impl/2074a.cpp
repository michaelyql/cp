#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int l, r, d, u;
	cin >> l >> r >> d >> u;
	if (u == d && u == l && u == r) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
