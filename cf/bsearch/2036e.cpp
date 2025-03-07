#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, q;
  cin >> n >> k >> q;
  vvi a(n + 1, vi(k + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j <= k; j++) {
    for (int i = 2; i <= n; i++) {
      a[i][j] |= a[i - 1][j];
    }
  }
  // cout << endl << "new matrix: " << endl;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= k; j++) {
  //     cout << a[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int m;
  int region, limit;
  char sign;
  while (q--) {
    cin >> m;
    int minR = 1, maxR = n;
    int l, r; // search boundaries
    bool ok = true;
    while (m--) {
      cin >> region >> sign >> limit;
      // cout << "region: " << region + 1 << ", sign: " << sign << ", limit: " << limit << endl;
      if (sign == '<') {
        // find largest i such that a[i][region] < limit
        l = 0, r = n;
        while (l < r) {
          int mid = l + (r - l) / 2; 
          if (mid == l && a[mid][region] < limit && l == r - 1) {
            mid = r;
          }
          if (a[mid][region] < limit) {
            l = mid;
          } else {
            r = mid - 1;
          }
        }
        if (l == 0) {
          ok = false;
        } else {
          maxR = min(maxR, l);
        }
      } else {
        // find smallest i such that a[i][region] > limit
        l = 1, r = n + 1;
        while (l < r) {
          int mid = l + (r - l) / 2;
          if (a[mid][region] > limit) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        if (r == n + 1) {
          ok = false;
        } else {
          minR = max(minR, r);
        }
      }
      // cout << "minR: " << minR << ", maxR: " << maxR << endl;
    }
    if (!ok || minR > maxR) {
      cout << -1 << endl;
    } else {
      cout << minR << endl;
    }
  }
}
