#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	ll n, k;
	cin >> n >> k;
	if (n & 1) {
		int add = 0;
		if (k & 1) {
			n -= k;
			k--;
			add = 1;
		}
		cout << (n + k - 1) / k + add << endl;
	} else {
		if (k & 1) k--;
		cout << (n + k - 1) / k << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
