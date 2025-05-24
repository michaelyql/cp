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
	int n;
	cin >> n;
	vi d(n), l(n), r(n);
	rep(i, 0, n) cin >> d[i];
	rep(i, 0, n) {
		cin >> l[i];
		cin >> r[i];
	}
	
	pair<int, int> cur {0, 0};
	
	vector<pair<int, int>> f(n);
	
	rep(i, 0, n) {
		if (d[i] == -1) {
			cur = { cur.first, cur.second + 1 };
		} else {
			cur = { cur.first + d[i], cur.second + d[i] };
		}
		if (cur.first > r[i] || cur.second < l[i]) {
			cout << -1 << endl;
			return;
		}
		cur = { max(l[i], cur.first), min(r[i], cur.second) };
		
		f[i] = cur;
	}
	
	pair<int, int> prev { l[n - 1], r[n - 1] };
	
	vector<pair<int, int>> b(n);
	
	for (int i = n - 1; i >= 0; i--) {
		b[i] = prev;
		
		if (i == 0) break;
		
		if (d[i] == -1) {
			prev = { prev.first - 1, prev.second }; 
		} else {
			prev = { prev.first - d[i], prev.second - d[i] };
		}
		
		prev = { max(prev.first, l[i - 1]), min(prev.second, r[i - 1]) };
	}
	
	int cur_h = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == -1) {
			if (f[i].first <= cur_h && cur_h <= f[i].second 
				&& b[i].first <= cur_h && cur_h <= b[i].second) {
				d[i] = 0;
			} else {
				d[i] = 1;
			}
		} 
		cur_h += d[i];
	}
	
	rep(i, 0, n) cout << d[i] << " ";
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
