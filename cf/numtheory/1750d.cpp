#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	
	// factorize a[0]
	vector<int> factors;
	int x = a[0];
	for (int d = 2; d * d <= x; d++) {
		if (x % d == 0) {
			while (x % d == 0) {
				x /= d;
			}
			factors.push_back(d);
		}
	}
	if (x > 1) {
		factors.push_back(x);
	}

	ll res = 1;
	rep(i, 1, n) {
		if (a[i - 1] % a[i] != 0) {
			cout << 0 << endl;
			return;
		}
		int g = a[i - 1] / a[i];
		int till = m / a[i];
		vector<int> g_factors;
		rep(j, 0, factors.size()) {
			if (g % factors[j] == 0) {
				g_factors.push_back(factors[j]); 
			}
		}
		
		int sz = (int) g_factors.size();
		int s = 0;
		for (int mask = 0; mask < (1 << sz); mask++) {
			int product = 1;
			int cnt = 0;
			for (int j = 0; j < sz; j++) {
				if (mask & (1 << j)) {
					product *= g_factors[j];
					cnt++;
				}
			}
			if (cnt % 2 == 0) {
				s += till / product;
			} else {
				s -= till / product;
			}
		}
		res = res * s % MOD;
	}
	cout << res << endl;
	
	/*
	gcd(b[i]  , a[i - 1]) = a[i]
	gcd(a[i]*k, a[i - 1]) = a[i]
	b[i] < a[i - 1]
	a[i]*k < a[i - 1]
	1 <= k < a[i-1]/a[i]
	gcd(k, a[i - 1]/a[i]) = 1
	*/
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
