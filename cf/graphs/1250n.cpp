#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 1e5 + 10; // Max number of wires
int last[N]; // Last node in each group to be found by dfs

void dfs(int u, size_t group, umap<int, vector<pii>> &adj, umap<int, bool> &vis) {
  vis[u] = true;
  bool end = true;
  for (pii &v : adj[u]) {
    if (!vis[v.first]) {
      dfs(v.first, group, adj, vis);
      end = false; // This node has other unvisited nodes, so it's not the last node to be searched in dfs
    }
  }
  if (end) last[group] = u;
}

void solve() {
  int n;
  cin >> n;
  unordered_map<int, vector<pii>> adj;
  unordered_map<int, bool> vis;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back({y, i});
    adj[y].push_back({x, i});
    vis[x] = false;
    vis[y] = false;
  }
  size_t group = 1; // Index of current group
  for (auto it = vis.begin(); it != vis.end(); it++) {
    int u = it->first;
    bool visited = it->second;
    if (!visited) {
      // cout << "Group: " << group << endl;
      dfs(u, group, adj, vis);
      // cout << endl;
      group++;
    }
  }
  cout << group - 2 << endl; // Min time needed
  int head = last[1]; // The node to join all other connected components to
  for (size_t g = 2; g < group; g++) {
    cout << adj[last[g]].front().second << " " << last[g] << " " << head << endl;
  }
}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
