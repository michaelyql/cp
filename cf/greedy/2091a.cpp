#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	cin >> n;
	int one = 0, two = 0, three = 0, five = 0, zero = 0;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	rep(i, 0, n) {
		if (a[i] == 0) zero++;
		else if (a[i] == 1) one++;
		else if (a[i] == 2) two++;
		else if (a[i] == 3) three++;
		else if (a[i] == 5) five++;
		
		if (zero >= 3 && one >= 1 && two >= 2 && three >= 1 && five >= 1) {
			cout << i + 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
