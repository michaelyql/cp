#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int deg[N];
int A[N];
vector<int> adj[N];
int n, m;

int dfs(int u, int k, int p = -1) {
	// leaf node
	if (deg[u] == 1 && p != -1 && k <= m) {
		return 1;
	}
	
	// more than m consecutive cats on current path
	if (k > m) {
		return 0;
	}
	
	int ret = 0;
	for (auto& v : adj[u]) {
		if (v == p) continue;
		if (A[v]) {
			ret += dfs(v, k + 1, u);
		} else {
			ret += dfs(v, 0, u);
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	cout << dfs(1, A[1]) << endl;
}
