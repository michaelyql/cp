#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n, x;
	cin >> n >> x;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());
	int teams = 0;
	
	ll cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] >= x) {
			teams++;
		} else {
			cnt += 1;
			if (cnt * a[i] >= x) {
				cnt = 0;
				teams++;
			}
		}
	}
	
	cout << teams << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
