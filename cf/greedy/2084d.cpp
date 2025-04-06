#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

/*
const int MOD = 1e9 + 7;

int bpow(int a, int b) {
	a %= MOD;
	int res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return res;
}
*/

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int M;
	if (n - m * k <= k) M = k;
	else M = n / (m + 1);
	rep(i, 0, n) cout << i % M << " ";
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
