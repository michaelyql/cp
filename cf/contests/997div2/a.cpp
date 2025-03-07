#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (i == 0) {
      continue;
    } else {
      ans += (x + y) * 2;
    }
  }
  ans += m * 4;
  cout << ans << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
