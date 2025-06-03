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

void solve() {
	int n, m;
	cin >> n >> m;
	vi c(m);
	rep(i, 0, m) cin >> c[i];
	sort(all(c));
	int i = 0, j = m - 1;
	rep(k, 0, n / 2) {
		rep(t, 0, 3) cout << c[i] << " " << c[j] << " ";
		cout << endl;
		rep(t, 0, 3) cout << c[j] << " " << c[i] << " ";
		cout << endl;
		i++, j--;
	}
	if (n & 1) {
		rep(k, 0, 3) cout << c[i] << " " << c[j] << " ";
		cout << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
