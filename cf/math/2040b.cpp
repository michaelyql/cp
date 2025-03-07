#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int dp[N];

int solve(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	if (dp[n] != 0) return dp[n];
	return dp[n] = solve((n + 1) / 2 - 1) + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
}
