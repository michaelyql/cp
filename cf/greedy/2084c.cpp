#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
void swap(int i, int j, vi& a, vi& pos) {
	pos[a[i]] = j;
	pos[a[j]] = i;
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
 
void solve() {
	int n;
	cin >> n;
	vi a(n), b(n), p(n + 1);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	int bad = 0;
	rep(i, 0, n) {
		if (a[i] == b[i]) {
			bad++;
		} 
		if (p[a[i]] == 0) {
			p[a[i]] = b[i];	
			p[b[i]] = a[i];
		} else {
			if (b[i] != p[a[i]]) {
				cout << -1 << endl;
				return;
			} 
		}
	}
	if (bad >= 2) {
		cout << -1 << endl;	
		return;
	}
	vector<pii> ops;
	vi pos(n + 1);
	rep(i, 0, n) pos[a[i]] = i;
 
	if (bad) {
		rep(i, 0, n) {
			if (a[i] == p[a[i]]) { 
				if (i != n / 2) {
					ops.push_back({ i + 1, n / 2 + 1 });
					swap(i, n/2, a, pos);
				}
				break;
			}
		}
	}
 
	rep(i, 0, n / 2) {
		if (a[n - 1 - i] == p[a[i]]) {
			continue;
		}
		int k = pos[p[a[i]]];
		ops.push_back({ k + 1, n - i });
		swap(k, n - 1 - i, a, pos);
	}
	cout << ops.size() << endl;
	rep(i, 0, ops.size()) {
		cout << ops[i].first << " " << ops[i].second << endl;
	}
} 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
