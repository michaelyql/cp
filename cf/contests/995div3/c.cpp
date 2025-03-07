#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> ls(m), q(k);
  for (int i = 0; i < m; i++) cin >> ls[i];
  for (int i = 0; i < k; i++) cin >> q[i];
  if (k < n - 1) {
    for (int i = 0; i < m; i++) cout << "0";
    cout << endl;
    return;
  }
  // k is either n-1 or n
  if (k == n) {
    for (int i = 0; i < m; i++) cout << "1";
    cout << endl;
    return;
  }
  // k is n-1
  int first_missing = 1;
  bool updated = false;
  for (int i = 0; i < k; i++) {
    if (q[i] != i + 1) {
      first_missing = i + 1;
      updated = true;
      break;
    }
  }
  if (!updated) first_missing = n;
  for (int i = 0; i < m; i++) {
    if (ls[i] == first_missing) cout << "1";
    else cout << "0";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
