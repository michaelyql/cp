#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5 + 5;
vector<int> adj[N];
int dist[N]; // distance to root

void dfs(int u, int p, int height) {
	dist[u] = height;
	for (auto& v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, height + 1);
	}
}

void solve() {
	int n, st, en;
	cin >> n >> st >> en;
	
	rep(i, 1, n + 1) {
		adj[i].clear();
	}
	
	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(en, -1, 0);
	vector<vector<int>> heights(n);
	for (int u = 1; u <= n; u++) {
		heights[dist[u]].push_back(u); 
	}
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < heights[i].size(); j++) {
			cout << heights[i][j] << " ";
		}
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
