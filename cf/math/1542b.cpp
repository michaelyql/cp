#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == 1) { // need this condition to protect against infinite loop for pw *= a
      if ((n - 1) % b == 0) cout << "Yes" << endl;
      else cout << "No" << endl;
      continue;
    }
    bool ok = false;
    for (long long pw = 1; pw <= n; pw *= a) { // long long to avoid tle
      if ((n - pw) % b == 0) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
}
