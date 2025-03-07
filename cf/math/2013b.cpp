#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll x = accumulate(a.begin(), a.end() - 2, (ll) 0);
    ll ans = a[n - 1] - a[n - 2] + x;
    cout << ans << endl;
  }
}
