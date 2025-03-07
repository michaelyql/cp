#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {

}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int x = a + b + c;
    if (n % x == 0) {
      cout << 3 * (n / x) << endl;
      continue;
    } else {
      int y = n % x;
      int ans = 3 * (n / x);
      if (y <= a) {
        ans += 1;
      } else if (y <= a + b) {
        ans += 2;
      }
      else ans += 3;
      cout << ans << endl;
    }
  }
}
