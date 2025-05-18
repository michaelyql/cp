#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
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
 
class comp {
public: 
	bool operator () (const int& p1, const int& p2) const {
		return p1 > p2; 
	}
};
 
void solve() {
	int n;
	cin >> n;
	vi a(n);
	map<int, vector<int>, comp> frontier;
	rep(i, 0, n) {
		cin >> a[i];
		if (frontier.find(a[i]) == frontier.end()) {
			frontier[a[i]] = { i };
		} else {
			frontier[a[i]].push_back(i);
		}
	}
	int ans = 0;
	vector<bool> ok(n, false), expand(n);
	auto it = frontier.begin();
	int k = (*it).first;
	auto& p = (*it).second;
	for (int& i : p) {
		if (ok[i]) continue;
		ans++;
		int j = i + 1;
		while (j < n && a[j] == k) {
			ok[j] = true;
			j++;
		}
		if (i > 0) ok[i - 1] = true;
		if (j < n) ok[j] = true;
	} 
	it++;
	for (; it != frontier.end(); it++) {
		int v = (*it).first;
		auto& indices = (*it).second;
		// check which indices are not reachable from current frontier
		for (int& i : indices) {
			if (ok[i]) {
				if (expand[i]) continue;
				expand[i] = true;
				int j = i + 1;
				while (j < n && a[j] == v) {
					ok[j] = expand[j] = true;
					j++;
				}
				if (j < n) ok[j] = true;
				j = i - 1;
				while (j >= 0 && a[j] == v) {
					ok[j] = expand[j] = true;
					j--;
				}
				if (j >= 0) ok[j] = true;
			}
		}
		for (int& i : indices) {
			if (!ok[i]) {
				ans++;
			} 
			if (i < n - 1) ok[i + 1] = true;
			if (i > 0) ok[i - 1] = true;
		}
	}
	cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
