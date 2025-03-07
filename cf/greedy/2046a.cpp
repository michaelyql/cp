#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 5002;
int r1[N], r2[N];
bool c1[N], c2[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> r1[i];
  for (int i = 0; i < n; i++) cin >> r2[i];
  memset(c1, false, n);
  memset(c2, false, n);
  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (r1[i] > r2[i]) {
      ans += r1[i];
      c1[i] = true;
    } else {
      ans += r2[i];
      c2[i] = true;
    }
  }
  int k = -1e9;
  for (int i = 0; i < n; i++) {
    if (!c1[i]) {
      k = max(k, r1[i]);
    } else {
      k = max(k, r2[i]);
    }
  }
  ans += k; 
  cout << ans << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
