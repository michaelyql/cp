#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
	int x, k;
	cin >> x >> k;
	if (k == 1) {
		if (x == 1) {
			cout << "NO" << endl;
			return;
		}
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				cout << "NO" << endl;
				return;
			}
		}
		cout << "YES" << endl;
	} else {
		if (x == 1 && k == 2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;	
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
