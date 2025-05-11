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

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void solve() {
	int n;
	cin >> n;
	vvi a(n, vi(n, 0));
	int dir = 0, val = 0;
	int x = (n-1)/2, y = (n-1)/2;
	a[y][x] = val++;
	for (int len = 1; val < n * n; len++) {
		for (int run = 0; run < 2 && val < n * n; run++) {
			for (int step = 0; step < len && val < n * n; step++) {
				x += dx[dir];
				y += dy[dir];
				a[y][x] = val++;
			}
			dir = (dir + 1) % 4;
		}
	}
	rep(i, 0, n) {
		rep(j, 0, n) cout << a[i][j] << " ";
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
