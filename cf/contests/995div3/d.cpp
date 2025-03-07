#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// returns number of pairs (i,j), i < j such that sum - ai - aj < x
ll calcLessThanX(ll X, vector<int> &a, ll sum) {
  ll pairs = 0;
  int j = 0;
  int n = a.size();
  for (int i = n - 1; i >= 0; i--) {
    while (j < n && sum - a[i] - a[j] >= X) {
      j++;
    }
    pairs += n - j;
  }
  for (int i = 0; i < n; i++) {
    if (sum - a[i] * 2 < X) pairs--;
  }
  return pairs / 2;
}

void solve() {
  int n;
  ll x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  cout << calcLessThanX(y + 1, a, sum) - calcLessThanX(x, a, sum) << endl;
}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
