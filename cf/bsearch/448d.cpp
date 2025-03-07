#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool ok(ll x, int n, int m, ll k) { // be careful of the data type, k needs to be ll, not int
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += min((ll)m, x / i);
  }
  if (cnt >= k) return true;
  return false;
}

int main() {
  int n, m;
  ll k;
  cin >> n >> m >> k;
  ll low = 1, high = (ll) n * m; // signed integer overflow from n * m
  if (k == 1) {
    cout << 1 << endl;
    return 0;
  }

  while (low < high) {
    ll mid = low + (high - low) / 2;
    if (ok(mid, n, m, k)) high = mid;
    else low = mid + 1;
  }
  cout << low << endl;
}
