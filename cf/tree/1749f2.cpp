#include <bits/stdc++.h>
using namespace std;

int n;

const int N = int(2e5) + 55; 
vector<int> adj[N]; // adjacency list

const int LOG = 18;
int up[N][LOG]; // binary lifting 
// 2^20 roughly 10^6, 2^18 roughly 262,000 or 2.62e5, enough to cover the max depth of the tree 

int p[N];

void solve() {

}

// build parent array
void dfs(int u, int pr) {
  p[u] = pr;
  for (int v : adj[u]) {
    if (v == pr) continue;
    dfs(v, u);
  }
}

void build_ancestors(int sz) {
  for (int v = 0; v < sz; v++) {
    up[v][0] = p[v]; // 2^0-th parent of v is just parent of v
    for (int j = 1; j < LOG; j++) { // 2^LOG exceeds max depth of tree, so only iterate until (LOG - 1)
      up[v][j] = up[up[v][j - 1]][j - 1];
    }
  }
}

int getKthAncestor(int node, int k) {
  for (int i = 0; i < LOG; i++) {
    if (k & (1 << i)) {
      node = up[node][i];
    }
  }
  return node;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  build_ancestors(n);
}
