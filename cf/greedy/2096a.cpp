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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> lt, gt;
	vector<bool> used(n + 1, false);
	rep(i, 0, n - 1) {
		if (s[i] == '<') lt.push_back(i);
		else gt.push_back(i);
	}
	vector<int> ans(n);
	int x = 1;
	if (!lt.empty()) {
		for (int i = lt.size() - 1; i >= 0; i--) {
			ans[lt[i] + 1] = x;
			used[x] = true;
			x++;
		}
	}
	x = n;
	if (!gt.empty()) {
		for (int i = gt.size() - 1; i >= 0; i--) {
			ans[gt[i] + 1] = x;
			used[x] = true;
			x--;
		}
	}
	x = 1;
	while (used[x]) x++;
	ans[0] = x;
	rep(i, 0, n) cout << ans[i] << " ";
	cout << endl;
	
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
