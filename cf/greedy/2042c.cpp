#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	vector<int> v;
	int x = 0;
	for (int i = n - 1; i > 0; i--) {
		if (s[i] == '1') x++;
		else x--;
		if (x > 0) v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	int ans = 1;
	while (k > 0 && !v.empty()) {
		k -= v.back();
		v.pop_back();
		ans++;
	}
	if (k > 0) cout << -1 << endl;
	else cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
