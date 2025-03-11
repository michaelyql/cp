#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	/* 
	sort sequence b ascending
	a1 = a2 - a3 + a4 - a5 ... + a_2n - a_(2n+1)
	a1 - a2 + a3 - a4 + a5 ... + a_(2n-1) + a_(2n+1) = a_2n
	a1 + (a3 - a2) + (a5 - a4) + ... + (a_(2n-1) - a_(2n-2)) + a_(2n+1) = a_2n
	since a3 > a2, a5 > a4, a_i > a_(i-1), the terms are all > 0
	
	so the final value is 
	a_2n = a1 + k1 + k2 + k3 + ... + kx + a_(2n+1) > a_(2n+1) 
	since all the terms are positive 
	so a_2n will be a value that is distinct and has not appeared in the array before
	*/
	
	int n;
	cin >> n;
	vi b(2 * n + 1);
	rep(i, 1, 2 * n + 1) cin >> b[i];
	sort(b.begin() + 1, b.end()); 
	vector<ll> a(2 * n + 5);
	ll sum = 0;
	for (int i = 1; i < n; i++) { 
		a[i * 2] = b[i];
		sum -= b[i];
	}
	for (int i = n; i <= 2 * n; i++) {
		a[2 * (i - n) + 1] = b[i];
		sum += b[i];
	}
	a[2 * n] = sum;
	for (int i = 1; i <= 2 * n + 1; i++) {
		cout << a[i] << " ";
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

