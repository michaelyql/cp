#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n, x;
	cin >> n >> x;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int sum = accumulate(a.begin(), a.end(), 0);
	if (sum % n == 0 && sum / n == x) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
