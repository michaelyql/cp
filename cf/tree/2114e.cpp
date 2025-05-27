#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
#define debug
 
#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void search(int u, int p, vvi& adj, 
	vector<ll>& max_threat, vector<ll>& min_threat, vi& a, vector<bool>& vis) {
		
	if (vis[u]) return;
	vis[u] = true;
	
	if (p != 0) {
		if (min_threat[p] < 0) {
			max_threat[u] -= min_threat[p]; 
		}
		min_threat[u] -= max_threat[p];
	}
	
	for (auto v : adj[u]) {
		search(v, u, adj, max_threat, min_threat, a, vis);
	}
	
}

void solve() {
	int n;
	cin >> n;
	vi a(n + 1);
	rep(i, 1, n + 1) cin >> a[i];
	vvi adj(n + 1); 
	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<ll> max_threat(n + 1, 0);
	vector<ll> min_threat(n + 1, 0);
	vector<bool> vis(n + 1, false);
	
	rep(i, 1, n + 1) {
		max_threat[i] = min_threat[i] = a[i];
	}
	
	search(1, 0, adj, max_threat, min_threat, a, vis);
	
	for (int i = 1; i <= n; i++) {
		cout << max_threat[i] << " ";
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
