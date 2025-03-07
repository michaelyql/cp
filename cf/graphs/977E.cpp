#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
bool vis[N];
vector<int> adj[N];
int deg[N];

bool search(int first, int u, int p = -1) {
	vis[u] = true;
	if (deg[u] != 2) return false;
	for (auto &v : adj[u]) {
		if (v == p) continue;
		if (v == first && p != -1) return true;
		if (!vis[v]) return search(first, v, u);
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (search(i, i)) ans++;
		}
	}
	cout << ans << endl;
}
