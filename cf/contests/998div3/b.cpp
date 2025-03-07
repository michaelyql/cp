#include <bits/stdc++.h>
// #include "helpers.cpp"
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
  vector<int> a(m);
  vector<int> p(n);
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[j];
    }
    if (ok) {
      sort(a.begin(), a.end());
      // cout << a;
      for (int j = 0; j < m - 1; j++) {
        if (a[j] != a[j + 1] - n) {
          ok = false;
          break;
        }
      }
      p[a[0]] = i + 1;
    }
  }
  if (!ok) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
