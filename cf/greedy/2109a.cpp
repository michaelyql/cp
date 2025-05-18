#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define debug
 
#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	int v = 0;
	rep(i, 0, n) {
		cin >> a[i];
		v += a[i];
	}
	if (v == n) {
		cout << "Yes" << endl;
		return;
	} 
	rep(i, 0, n - 1) {
		if (a[i] == 0 && a[i + 1] == 0) {
			cout << "Yes" << endl;
			return;
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
