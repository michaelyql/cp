#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
// #define debug
 
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

int f[11] = { 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

int n, m;

bool ok(int i, vi& w, vi& l, vi& h) {
	int a = w[i], b = l[i], c = h[i];
	
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);

	if (f[n] > a) return false;
	
	if (f[n] + f[n - 1] <= c) return true;
	if (f[n] + f[n - 1] <= b) return true;
	if (f[n] + f[n - 1] <= a) return true;
	
	return false;
}

void solve() {
	cin >> n >> m;
	vi w(m), l(m), h(m);
	rep(i, 0, m) {
		cin >> w[i];
		cin >> l[i];
		cin >> h[i];
	}
	rep(i, 0, m) {
		if (ok(i, w, l, h)) cout << 1;
		else cout << 0;
	}
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
