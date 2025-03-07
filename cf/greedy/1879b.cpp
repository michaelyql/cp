#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 3e5 + 5;
ll a[N];
ll b[N];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll amin = 1e9 + 2, bmin = 1e9 + 2;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      amin = min(amin, a[i]);
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      bmin = min(bmin, b[i]);
    }
    ll x = accumulate(a, a + n, (ll) 0);
    ll y = accumulate(b, b + n, (ll) 0);
    ll ans = min(x + bmin * n, y + amin * n);
    cout << ans << endl;
  }
}
