#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> deg(n + 1);
		vector<vector<int>> adj(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			deg[u]++;
			deg[v]++;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> a(n + 1);
		iota(a.begin() + 1, a.end(), 1);
		sort(a.begin() + 1, a.end(), [&](const int& u, const int& v) {
			return deg[u] > deg[v];
		});
		if (n <= 5) {
			cout << n - 2 << endl;
			continue;
		}
		vector<int> b;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == deg[a[1]]) b.push_back(i);
		}
		bool neighbour = false;
		for (auto &v : adj[a[1]]) {
			if (v == a[2]) {
				neighbour = true;
				break;
			}
		}
		if (b.size() == 1) {
			vector<int> c;
			for (int i = 1; i <= n; i++) {
				if (deg[i] == deg[a[2]]) c.push_back(i);
			}
			if (c.size() == 1) {
				if (neighbour) cout << deg[a[1]] + deg[a[2]] - 2 << endl;
				else cout << deg[a[1]] + deg[a[2]] - 1 << endl;	
			} else {
				unordered_set<int> adjacent;
				for (auto & v : adj[a[1]]) {
					adjacent.insert(v);
				}
				bool found = false;
				for (auto & x : c) {
					if (adjacent.find(x) == adjacent.end()) {
						found = true;
						break;
					}
				}
				if (found) {
					cout << deg[a[1]] + deg[a[2]] - 1 << endl;
				} else {
					cout << deg[a[1]] + deg[a[2]] - 2 << endl;
				}
			}
		} else {
			int ans;
			if (neighbour) {
				ans = deg[a[1]] + deg[a[2]] - 2;
			} else {
				ans = deg[a[1]] + deg[a[2]] - 1;
			}
			if (b.size() > 2) {
				ans = deg[a[1]] + deg[a[2]] - 1;
			}
			cout << ans << endl;
		}
	}
}
