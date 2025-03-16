#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MAX_K = 20;
const int N = 2e5 + 5;
int st[MAX_K][N];


void solve() {
	int n, q;
	cin >> n >> q;
	vi a(n), diff(n-1);
	rep(i, 0, n) cin >> a[i];
  rep(i, 0, n - 1) {
    diff[i] = abs(a[i + 1] - a[i]);
    st[0][i] = diff[i];
  }
	for (int i = 1; i < MAX_K; i++) {
		for (int j = 0; j + (1 << i - 1) < n - 1; j++) {
			st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << i - 1)]); 
		}
	}
	int l, r;
	while (q--) {
		cin >> l >> r;
    if (l == r) {
      cout << 0 << endl;
      continue;
    }
		int sz = r - l;
		l--;
    r -= 2;
		int level = 0;
		while ((1 << level + 1) <= sz) level++;
		int GCD = gcd(st[level][l], st[level][r - (1 << level) + 1]);
		cout << GCD << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
