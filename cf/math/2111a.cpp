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

int x;

bool ok(ll i) {
	int ops = 0;
	ll cur = 0;
	while (cur * 2 + 1 < x) {
		ops += 2;
		cur = cur * 2 + 1;
	}
	ops += 3;
	if (ops <= i) return true;
	else return false;
}

void solve() {
	cin >> x;
	for (int i = 1; i <= 61; i++) {
		if (ok(i)) {
			cout << i << endl;
			return;
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
