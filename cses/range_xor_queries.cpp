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
  int n, q;
  cin >> n >> q;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vi pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];
    pref[i] ^= a[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (pref[l - 1] ^ pref[r]) << endl;
  }
}
