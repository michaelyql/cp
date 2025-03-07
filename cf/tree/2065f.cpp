#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 5;
int a[N];
bool ok[N];
unordered_set<int> un[N]; // unique neighbour of node i
 
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		un[i].clear();
		ok[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		if (a[u] == a[v]) ok[a[u]] = true;
		else {
			if (un[u].find(a[v]) != un[u].end()) {
				ok[a[v]] = true;
			} 
			
			if (un[v].find(a[u]) != un[v].end()) {
				ok[a[u]] = true;
			} 
			un[u].insert(a[v]);
			un[v].insert(a[u]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ok[i]) cout << 1;
		else cout << 0;
	}
	cout << endl;
 
}
 
int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
