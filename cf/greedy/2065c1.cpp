#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int dp[N][2];

bool check(int i, bool flip, vector<int>& a, vector<int>& b, int n, int m) {
		
	int val = a[i];
	if (flip) val = b[0] - val; 
	
	if (i == n - 1) {
		return true;
	}
	
	if (dp[i][flip] != -1) return dp[i][flip];

	return dp[i][flip] = (a[i + 1] >= val && check(i + 1, false, a, b, n, m)) 
		|| (b[0] - a[i + 1] >= val && check(i + 1, true, a, b, n, m));
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(m);
	cin >> b[0];
	if (n == 1) {
		cout << "YES" << endl;
		return;
	}
	if (check(0, false, a, b, n, m) || check(0, true, a, b, n, m)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
