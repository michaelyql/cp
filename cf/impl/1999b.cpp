#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  int ans = 0;
  if ((a1 > b1 && a2 > b2) || (a1 == b1 && a2 > b2) || (a1 > b1 && a2 == b2)) {
    ans += 2;
  }
  if ((a1 > b2 && a2 > b1) || (a1 == b2 && a2 > b1) || (a1 > b2 && a2 == b1)) {
    ans += 2;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
