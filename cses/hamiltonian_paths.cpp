#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 21;
int dp[1 << N][N];
vector<int> adj[N];
int n, m;
const int MOD = 1e9 + 7;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[v].push_back(u);
	}
	
	dp[1][0] = 1;
	
	for (int S = 2; S < (1 << n); S++) {
		if ((S & 1) == 0) continue;
		if (S & (1 << (n - 1)) && S != ((1 << n) - 1)) continue;
		
		for (int i = 0; i < n; i++) {
			if ((S & (1 << i)) == 0) continue;
			int prev = S - (1 << i);
			
			for (int v : adj[i]) {
				dp[S][i] += dp[prev][v];
				dp[S][i] %= MOD;
			}
		}
	}
	
	cout << dp[(1 << n) - 1][n - 1] << endl;
}
