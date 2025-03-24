#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	cin >> n;
	vi a(n), b;
	rep(i, 0, n) cin >> a[i];
	int i = 0;
	while (i < n) {
		b.push_back(a[i]);
		while (i + 1 < n && a[i] == a[i + 1]) i++;
		i++;
	}
	int k = b.size();
	i = 0;
	int rem = 0;
	while (i < k - 1) {
		int sz = 1;
		if (b[i] < b[i + 1]) {
			while (i + 1 < k && b[i] < b[i + 1]) {
				i++;
				sz++;
			}
		} else {
			while (i + 1 < k && b[i] > b[i + 1]) {
				i++;
				sz++;
			}
		}
		rem += (sz - 2);
	}
	cout << b.size() - rem << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
