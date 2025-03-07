#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

int n, k;

void solve() {
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  vector<int> cnt = {1};
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1]) {
      cnt.back()++;
    } else {
      cnt.emplace_back(1);
    }
  }
  sort(cnt.begin(), cnt.end());
  size_t m = cnt.size();
  for (size_t i = 0; i < m - 1; i++) {
    if (cnt[i] > k) {
      cout << m - i << endl;
      return;
    }
    k -= cnt[i];
  }
  cout << 1 << endl;
}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
