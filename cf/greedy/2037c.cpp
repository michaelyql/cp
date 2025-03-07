#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	if (n < 5) {
		cout << -1 << endl;
		return;
	}
	for (int i = 1; i <= n; i += 2) {
		if (i == 5) continue;
		cout << i << " ";
	}
	cout << "5 4 ";
	for (int i = 2; i <= n; i+= 2) {
		if (i == 4) continue;
		cout << i << " ";
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

// 1 2 3 4 5
// 1 3 5 4 2 6 
