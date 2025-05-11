#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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
	rep(i, 0, n) cin >> a[i];
	a[0] = abs(a[0]);
	int need = (n + 1) / 2 - 1;
	int p = 0, q = 0;
	rep(i, 1, n) { 
		if (abs(a[i]) < a[0]) p++; 
		else q++; 
	}
	if (p <= need || q >= need) {
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
