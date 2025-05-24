#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

ll mod(ll x, int m) {
  return (x % m + m) % m;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<ll, int> freq;
  freq[0] = 1;
  ll psum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    psum += a[i];
    ll r = mod(psum, n);
    ans += freq[r];
    freq[r]++;
  }
  cout << ans << endl;
}
