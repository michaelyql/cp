#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  
  int neg_cnt = 0;
  int k = 1e9 + 10;
  for (int i = 0; i < n; i++) {
    c[i] += a[i] - b[i]; // have - need
    if (c[i] < 0) {
      neg_cnt++;
      k = min(k, c[i]);
    }
  }
  if (neg_cnt == 0) {
    cout << "YES" << endl;
    return;
  }
  if (neg_cnt == 1) {
    for (int i = 0; i < n; i++) {
      if (c[i] < 0) continue;
      if (c[i] < abs(k)) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
