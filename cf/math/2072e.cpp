#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	int k;
	cin >> k;
	
	int x = 0;
	int y = 0;
	
	vector<pii> ans;
	
	while (k > 0) {
		int m = 2; 
		
		while (m * (m - 1) / 2 <= k) m++;
		if (m > 2) m--;
		
		k -= m * (m - 1) / 2;
		
		for (int i = 0; i < m; i++) {
			ans.push_back({y, x++});
		}
		y++;
	}
	
	cout << ans.size() << endl;
	for (auto& [a, b] : ans) {
		cout << a << " " << b << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
