#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const int N = 1e5 + 7;
int deg[N];
vector<int> adj[N];
pair<int, int> edges[N];
int n, m, h, t;
int ans[2] = {-1, -1};

bool common[N];
bool marked[N];
bool vis[N];

bool check(int u, int v) {
  for (int w : adj[u]) if (w != v) marked[w] = true;
  int sz = 0;
  for (int w : adj[v]) if (marked[w] && w != u) {
    common[w] = true;
    sz++;
  }
  for (int w : adj[u]) marked[w] = false; // reset the marked array
  if (deg[u] - sz > h || deg[v] - sz > t) {
    ans[0] = u; ans[1] = v; 
    if (deg[v] - sz > t) memset(common, false, n);
    return true;
  }
  int give = deg[u] - h - 1; // give from u to v from common pool
  if (deg[v] - (sz - give) > t) {
    ans[0] = u; ans[1] = v;
    if (sz - give > 0) {
      int k = 1;
      for (int i = 0; i < sz - give; ) {
        if (common[k]) {
          common[k] = false;
          i++;
        }
        k++;
      }
    }
    return true;
  }
  give = deg[v] - t - 1; // give from v to u from common pool
  if (deg[u] - (sz - give) > h) {
    ans[0] = u; ans[1] = v;
    if (give > 0) {
      int k = 1;
      for (int i = 0; i < give; ) {
        if (common[k]) {
          common[k] = false;
          i++;
        }
        k++;
      }
    }
    return true;
  }
  memset(common, false, n);
  return false; // no answer found for this pair of u, v
}

int main() {
  cin.sync_with_stdio(false);
  cin >> n >> m >> h >> t;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    deg[a]++;
    deg[b]++;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
    edges[i] = {a, b};
  }
  for (pii &edge : edges) { // O(m)
    int u = edge.first, v = edge.second;
    if (deg[u] >= h + t + 1 && deg[v] >= h + t + 1) {
      ans[0] = u, ans[1] = v;
      break;
    }
    if ((deg[u] <= h && deg[u] <= t) || // u can't be either chest or stomach
      (deg[v] <= h && deg[v] <= t))
        continue;
    if (deg[u] > h && deg[v] > t) {
      if (check(u, v)) break;
    }
    if (deg[u] > t && deg[v] > h) {
      if (check(v, u)) break;
    }
  }
  if (ans[0] == -1) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << ans[0] << " " << ans[1] << endl;
    int k = 0;
    for (int v : adj[ans[0]]) {
      if (v == ans[1] || common[v]) continue;
      if (k >= h) break;
      cout << v << " "; 
      vis[v] = true;
      k++;
    }
    cout << endl;
    k = 0;
    for (int v : adj[ans[1]]) {
      // avoid repeated vertices
      if (v == ans[0] || vis[v]) continue; 
      if (k >= t) break;
      cout << v << " ";
      k++;
    }
    cout << endl;
  }
}
