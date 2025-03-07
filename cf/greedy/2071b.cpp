#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	cin >> n;
	ll v = 1ll * n * (n + 1) / 2;
	ll k = sqrt(v);
	if (k * k == v) {
		cout << -1 << endl;
		return;
	}  
	vi a(n);
	iota(a.begin(), a.end(), 1);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll next = sum + a[i];
		ll k = sqrt(next);
		if (k * k == next) {
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
		sum += a[i];
	}
	// ll jj = 0;
	for (auto& x : a) {
		cout << x << " ";
		// jj += x;
		// cout << "sum="<<jj<<endl;
		
		// int qq = sqrt(jj);
		// if (1ll * qq * qq == jj) {
		// 	cout << "BAD" << endl;
		// }
	}
	cout << endl;
	
} 


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
