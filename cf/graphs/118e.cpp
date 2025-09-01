#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
bool vis[MAX_N];
int low[MAX_N], disc[MAX_N];
int timer = 0;

bool dfs(int u, int p, vector<vector<int>>& g) {
	vis[u] = true;
	low[u] = disc[u] = ++timer;
	for (int v : g[u]) {
		if (v == p) continue;
		if (vis[v]) {
			low[u] = min(low[u], disc[v]);
		} else {
			bool ok = dfs(v, u, g);
			if (!ok) return false;
			low[u] = min(low[u], low[v]);
			if (disc[u] < low[v]) {
				// bridge
				return false;
			}
		}
	}
	return true;
}

void dfs1(int u, int p, vector<vector<int>>& g, set<pair<int, int>>& ans) {
	vis[u] = true;
	for (int v : g[u]) {
		if (v == p) continue;
		if (vis[v]) {
			if (ans.find({v, u}) == ans.end()) {
				ans.insert({u, v});
			}
		} else {
			ans.insert({u, v});
			dfs1(v, u, g, ans);	
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges[i] = {u, v};
	}
	bool ok = dfs(1, 0, g);
	if (!ok) cout << 0 << endl;
	else {
		memset(vis, 0, sizeof(vis));
		set<pair<int, int>> ans;
		dfs1(1, 0, g, ans);
		for (auto it = ans.begin(); it != ans.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
	}
}
