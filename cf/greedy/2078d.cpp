#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int ADD_LEFT = 0, ADD_RIGHT = 1;

int check(vector<pair<char, int>>& l, vector<pair<char, int>>& r, int j) {
	if (l[j].first == 'x' && r[j].first == 'x') {
		if (l[j].second > r[j].second) return ADD_LEFT;
		else return ADD_RIGHT;
	} else if (l[j].first == 'x') return ADD_LEFT;
	else return ADD_RIGHT;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<char, int>> l, r;
	char c;
	int v;
	rep(i, 0, n) {
		cin >> c >> v;
		l.push_back({ c, v });
		cin >> c >> v;
		r.push_back({ c, v });
	}
	vector<int> next(n), prev;
	rep(i, 0, n) {
		if (l[i].first == 'x' && r[i].first == 'x') {
			if (l[i].second == r[i].second) {
				prev.push_back(i);
			} else {
				if (!prev.empty()) {
					for (int j : prev) {
						next[j] = i;	
					}
					prev.clear();
				}
			}
		} else if (r[i].first == 'x' || l[i].first == 'x') {
			if (!prev.empty()) {
				for (int j : prev) {
					next[j] = i;	
				}
				prev.clear();
			}
		} 
	}
	ll lcnt = 1, rcnt = 1, add = 0;
	rep(i, 0, n) {
		if (l[i].first == '+' && r[i].first == '+') {
			add += l[i].second + r[i].second;
		} else if (l[i].first == 'x' && r[i].first == '+') {
			lcnt += add;
			add = r[i].second + lcnt * (l[i].second - 1);
		} else if (l[i].first == '+' && r[i].first == 'x') {
			rcnt += add;
			add = l[i].second + rcnt * (r[i].second - 1);
		} else {
			if (l[i].second == r[i].second) {
				if (next[i] != 0) {
					if (check(l, r, next[i]) == ADD_LEFT) {
						lcnt += add;
					} else {
						rcnt += add;
					}
					add = (lcnt + rcnt) *  (l[i].second - 1);
				} else {
					lcnt += add;
					lcnt *= l[i].second;
					rcnt *= r[i].second;
					add = 0;
				}
			} else {
				if (l[i].second > r[i].second) {
					lcnt += add;
				} else {
					rcnt += add;
				}
				add = lcnt * (l[i].second - 1) + rcnt * (r[i].second - 1);
			}
		}
	}
	cout << lcnt + rcnt + add << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
