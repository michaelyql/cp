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
	int n, k;
	cin >> n >> k;
	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	int s = -1;
	ll cnt = 0;
	rep(i, 0, n) {
		if (b[i] != -1) {
			if (s == -1) {
				s = a[i] + b[i];	
			} else {
				if (a[i] + b[i] != s) {
					cout << 0 << endl;
					return;
				}
			}
		}	
	}
	if (s == -1) {
		int mx = *max_element(a.begin(), a.end());
		int mn = *min_element(a.begin(), a.end());
		cout << mn + k - mx + 1 << endl;
	} else {
		rep(i, 0, n) {
			if (s - a[i] > k || s - a[i] < 0) {
				cout << 0 << endl;
				return;
			}
		}
		cout << 1 << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
