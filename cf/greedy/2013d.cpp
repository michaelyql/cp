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
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;
  ll sum = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sum += a[i];
    ll avg = sum / (n - i);
    if (a[i] <= avg) continue;
    // redistribute
    
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
