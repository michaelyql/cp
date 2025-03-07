#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {

	int n, x;
	cin >> n >> x;
	if (n == 1) {
		cout << x << endl;
		return;
	}
	cout << 0 << " ";
	
	int val = 0;
	
	vector<int> ans;
	
	for (int i = 1; i < n; i++) {
		if (i <= x && ((x ^ i) == (x - i))) {
			ans.push_back(i);
			val = val | i;
		} else {
			ans.push_back(x);
			val = x;
		}
	}
	
	if (val != x) {
		ans[ans.size() - 1] = x;
	}
	
	for (auto v : ans) {
		cout << v << " ";
	}

	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
