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
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	if (p == n) {
		cout << (q == m ? "YES" : "NO") << endl;
		return;
	}
	if (n % p == 0) {
		if ((n / p) * q == m) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
	
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
