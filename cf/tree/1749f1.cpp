#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> values;
vector<bool> vis;
vector<vector<int>> dist;
vector<vector<int>> adj;

void solve() {
  int qtype;
  cin >> qtype;
  if (qtype == 1) {
    int idx;
    cin >> idx;
    cout << values[--idx] << endl;
    return;
  } 
  int u, v, k, d;
  cin >> u >> v >> k >> d;
  u--; v--;
  if (u == v) {
    for (int i = 0; i < n; i++) {
      if (dist[u][i] <= d) values[i] += k;
    }
    return;
  }
  vector<bool> add(n, false);
  while (u != v) { // traverse the path
    for (int i = 0; i < n; i++) {
      if (add[i]) continue;
      add[i] = add[i] || (dist[u][i] <= d);
    }
    for (int next : adj[u]) {
      if (dist[next][v] < dist[u][v]) 
        u = next;
    }
  }
  for (int i = 0; i < n; i++) { // reached the end, check last vertex
    add[i] = add[i] || (dist[v][i] <= d);
  }
  for (int i = 0; i < n; i++) {
    if (add[i]) values[i] += k;
  }
}

void dfs(int src, int curr, int d) {
  vis[curr] = true;
  dist[src][curr] = d;
  for (int v : adj[curr]) {
    if (vis[v]) continue;
    dfs(src, v, d + 1);
  }
}

int main() {
  cin >> n;
  values.resize(n, 0);
  vis.resize(n, false);
  dist.resize(n, vector<int>(n, -1));
  adj.resize(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    vis.assign(n, false);
    dfs(i, i, 0);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    solve();
  }
}
