#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == a[1]) {
		cout << "Yes" << endl;
		return;
	}
	ll g = -1;
	rep(i, 1, n) {
		if (a[i] % a[0] == 0) {
			if (g == -1) g = a[i];
			else {
				g = gcd(a[i], g); 
				if (g == a[0]) {
					cout << "Yes" << endl;
					return;
				}
			}
		}
	}
	cout << "No" << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
