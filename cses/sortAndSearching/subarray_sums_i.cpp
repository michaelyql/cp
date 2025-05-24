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
  int n, x;
  cin >> n >> x;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll psum = 0;
  int i = 0, j = 0;
  ll ans = 0;
  while (i < n) {
    psum += a[i];
    while (psum >= x && j < n) {
      if (psum == x) ans++;
      psum -= a[j];
      j++;
    }
    i++;
  }
  cout << ans << endl;
}
