#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, s, m;
  cin >> n >> s >> m;
  int prev_r = 0;
  bool can = false;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    if (i == n - 1) {
      if (prev_r + s <= l || r + s <= m) can = true;
    } else {
      if (prev_r + s <= l) can = true;
      prev_r = r;
    }
  }
  cout << (can ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
