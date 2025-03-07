#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int n, k;
string s;
const int N = 3e5 + 5;
int a[N];

bool ok(int m) {
	vector<char> b;
	for (int i = 0; i < n; i++) {
		if (a[i] > m) {
			b.push_back(s[i]);
		}
	}
	int bcnt = 0;
	for (int i = 0; i < b.size(); ) {
		if (b[i] == 'B') {
			while (i < b.size() && b[i] == 'B') i++;
			bcnt++;
		} else {
			while (i < b.size() && b[i] == 'R') i++;
		}
	}
	if (bcnt <= k) return true;
	else return false;
}

void solve() {
	cin >> n >> k;
	cin >> s;
	int r = 0, l = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		r = max(r, a[i]);
	}
	while (l < r) {
		int m = l + (r - l) / 2;
		if (ok(m)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << r << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
