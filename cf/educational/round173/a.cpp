#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll solve(ll n) {
  if (n <= 3) return 1;
  return solve(n / 4) * 2;
}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
  }
}
