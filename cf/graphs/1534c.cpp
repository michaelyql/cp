#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 3;
int par[N];
int r[N];

const int MOD = 1e9 + 7;

int fast_exp(int a, int b) {
	if (b == 0) return 1;
	int c = fast_exp(1ll * a * a % MOD, b / 2);
	if (b & 1) return 1ll * a * c % MOD;
	else return c;
}

int find(int u) {
	if (par[u] == u) return u;
	return par[u] = find(par[u]);
}

void unite(int u, int v) {
	if (par[u] == par[v]) return;
	int u_p = find(u);
	int v_p = find(v);
	if (r[u_p] > r[v_p]) {
		par[v_p] = u_p;
		r[u_p]++;
	} else {
		par[u_p] = v_p;
		r[v_p]++;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> row1(n + 1), row2(n + 1);
	for (int i = 1; i <= n; i++) cin >> row1[i];
	for (int i = 1; i <= n; i++) cin >> row2[i];
	
	memset(r, 0, (n + 1) * 4);
	for (int i = 1; i <= n; i++) par[i] = i;
	
	for (int i = 1; i <= n; i++) {
		unite(row1[i], row2[i]);
	}
	
	unordered_set<int> seen;
	for (int i = 1; i <= n; i++) {
		int p = find(row1[i]);
		if (seen.find(p) == seen.end()) {
			seen.insert(p);
		}
	}
	
	
	int sz = seen.size();
	cout << fast_exp(2, sz) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
