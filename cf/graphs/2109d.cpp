#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
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

const int inf = 2e9;

void solve() {
	int n, m, l;
	cin >> n >> m >> l;
	vi a(l);
	int sum = 0, smallest_odd = inf;
	rep(i, 0, l) {
		cin >> a[i];
		sum += a[i];
		if (a[i] & 1) smallest_odd = min(smallest_odd, a[i]);
	}
	int max_even = 0, max_odd = 0;
	if (sum & 1) {
		max_odd = sum;
		max_even = sum - smallest_odd;
	} else {
		max_even = sum;
		if (smallest_odd != inf) max_odd = sum - smallest_odd;
	}
	vvi adj(n + 1);
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vvi dist(n + 1, vi(2, inf));
	queue<int> q;
	dist[1][0] = 0;
	for (int& v : adj[1]) q.push(v);  
	
	int d = 1;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int u = q.front();
			q.pop();
			if (dist[u][d % 2] != inf) continue;
			dist[u][d % 2] = d;
			for (int& v : adj[u]) q.push(v);
		}
		d++;
	}
	
	cout << 1; // 1 is always possible
	rep(i, 2, n + 1) {
		if (max_odd >= dist[i][1] || max_even >= dist[i][0]) cout << 1;
		else cout << 0;
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
