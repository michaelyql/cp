#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {
  ll k, l1, r1, l2, r2;
  cin >> k >> l1 >> r1 >> l2 >> r2;
  ll ans = 0;
  for (ll pw = 1; pw <= r2 / l1; pw *= k) {

    int b1 = max(l1, (l2 + pw - 1) / pw); // ceiling of l2 / k
    int b2 = min(r1, r2 / pw); // floor of r2 / k
    
    // cout << "b1: " << b1 << ", b2: " << b2 << ", b2 - b1 + 1: " << b2 - b1 + 1 << endl;
    ans += max(0, b2 - b1 + 1);
  }
  cout << ans << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
