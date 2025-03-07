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
  map<ll, int> freq;
  ll ans = 0;
  freq[0] = 1;
  for (int i = 0; i < n; i++) {
    psum += a[i];
    ans += freq[psum - x];
    freq[psum]++;
  }
  cout << ans << endl;
}
