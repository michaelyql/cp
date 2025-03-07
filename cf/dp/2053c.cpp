#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll split(int n, int k) {
	if (n < k) return 0;
	ll ret = 0;
	if (n & 1) ret += 1;
	return 2 * split(n / 2, k) + ret;
}

ll f(int n, int k) {
	if (n < k) return 0;
	ll ans = 0;
	ll mid_val = n / 2;
	if (n & 1) {
		mid_val++;
		ans += mid_val;
	} 
	return 2 * f(n / 2, k) + split(n / 2, k) * mid_val + ans;
}

void solve() {
	int n, k;
	cin >> n >> k; 
	cout << f(n, k) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
