#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int dash = 0, under = 0;
	for (char c: s) {
		if (c == '-') dash++;
		else under++;
	}
	if (dash == 0 || under == 0) {
		cout << 0 << endl;
		return;
	}
	int x = dash / 2;
	int y = dash - x;
	
	cout << 1ll * under * x * y << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
