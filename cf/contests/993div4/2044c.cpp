#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, a, b, c;
  cin >> m >> a >> b >> c;
  int ans = 0;
  ans += min(m, a); 
  ans += min(m, b);
  int remaining = 0;
  remaining += m - min(m, a);
  remaining += m - min(m, b);
  ans += min(remaining, c);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
