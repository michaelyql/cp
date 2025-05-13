#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using vi = vector<int>;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int ct = 1;
  vector<bool> arrive(n + 1);
  int p = 1; 
  int at, i;
  int ans = 0;

  rep(j, 0, n) {
    cin >> at >> i;
    arrive[i] = true;

    if (arrive[p]) {
      int _p = p;
      while (_p <= n && arrive[_p]) _p++;
      int dt = _p - p;
      p = _p;
      if (at <= ct) {
        ct += dt;
      } else {
        ans += at - ct;
        ct = at + dt;
      }
    } 
  }
  cout << ans << endl;
}
