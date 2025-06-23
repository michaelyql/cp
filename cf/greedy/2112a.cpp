
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;

void solve() {
	int a, x, y;
	cin >> a >> x >> y;
	if (a == x || a == y) {
		cout << "NO" << endl;
		return;
	} 
	if (x > y) swap(x, y);
	if (x == y) {
		cout << "YES" << endl;
	} else {
		if (a < x || a > y) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
