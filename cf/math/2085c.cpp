#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << -1 << endl;
		return;
	}
	if ((x & y) == 0) {
		cout << 0 << endl;
		return;
	}
	if (x < y) swap(x, y);
	
	int i;
	for (i = 30; i >= 0; i--) {
		if (x & (1 << i)) {
			break;
		}
	}
	i++;
	cout << (1 << i) - x << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
