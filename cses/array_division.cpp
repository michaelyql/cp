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
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll l = *max_element(a.begin(), a.end());
  ll r = accumulate(a.begin(), a.end(), 0ll);

  while (l < r) {
    ll m = l + (r - l) / 2;
    int divide = 1;
    ll sum = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] > m) {
        ok = false;
        break;
      }
      if (sum + a[i] <= m) {
        sum += a[i];
      } else {
        sum = a[i];
        divide++;
      }
    }
    if (!ok || divide > k) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << r << endl;
}
