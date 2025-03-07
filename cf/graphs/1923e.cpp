#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 2e5 + 7;
vector<int> adj[N];
size_t c[N];
size_t c_size[N];

size_t f() {

}

void reroot(int u) {

}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) adj[i].clear();
  memset(c_size, 0, n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    c_size[c[i]]++;
  } 
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  size_t ans = 0;
  for (int i = 1; i <= n; i++) {
    if (c_size[i]) ans += f();
  }
  cout << ans << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
