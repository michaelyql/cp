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
	int n, m, k;
	cin >> n >> m >> k;
	vvi a(n, vi(m, 0));
	rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
	vvi psum(m, vi(n + 1));
	rep(c, 0, m) {
		rep(r, 1, n + 1) {
			psum[c][r] = psum[c][r-1];
			psum[c][r] += a[r-1][c]; 
		}
	}
	int ans_score = 0, min_repl = 0;
	rep(c, 0, m) {
		int best_score = 0, removed = 0, cur_removed = 0; 
		rep(r, 0, n) {
			if (a[r][c] == 1) {
				int jump = min(k, n - r);
				int score = psum[c][r+jump] - psum[c][r];
				if (score > best_score) {
					removed = cur_removed;
					best_score = score;
				}
				cur_removed++;
			}	
		}
		ans_score += best_score;
		min_repl += removed;
	}
	cout << ans_score << " " << min_repl << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	solve();
}
