#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
int par[N];
int depth[N];

int mod(int x) {
  int ret = x % MOD;
  if (ret < 0) ret += MOD;
  return ret;
}

int find_root(int v) {
  if (par[v] == v) return v;
  int root = find_root(par[v]);
  depth[v] = mod((depth[v] + mod(depth[par[v]])));
  return par[v] = root;
}

int update(int v, int x, int i) {
  int root = find_root(v);
  if (root == v) {
    par[v] = i;
    return depth[v] = x;
  } else {
    int c = mod(depth[v] + x);
    depth[root] = c;
    par[root] = i;
    return c;
  }
}

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int v, x;
      cin >> v >> x;
      ans = mod(ans + update(v, mod(x), i));
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << "Depth of " << i << ": " << depth[i] << endl;
  // }
  // for (int i = 1; i <= n; i++) {
  //   cout << "Root of " << i << ": " << par[i] << endl;
  // }
  cout << ans << endl;
}
