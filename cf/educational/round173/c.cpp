#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> distinct_sums(vector<int> &a, int l, int r) {
  int n = a.size();
  int min_found = 0, max_found = 0; // empty subarray
  int acc = 0; // accumulated value over entire subarray
  for (int i = 0; i < n; ) {
    int chunk = a[i];
    while (i < n - 1 && a[i + 1] == a[i]) {
      chunk += a[i];
      i++;
    }
    acc += chunk;
    min_found = min(min_found, min(acc, chunk));
    max_found = max(max_found, max(acc, chunk));
    i++;
  }
  vector<int> ans(abs(max_found - min_found) + 1);
  iota(ans.begin(), ans.end(), min_found);
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x_idx = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != 1 && a[i] != -1) {
      x_idx = i;
      break;
    }
  }
  if (x_idx == -1 || a[x_idx] == 0) { // x doesn't exist in the array, or x is 0 so it makes no difference
    auto sums = distinct_sums(a, 0, n - 1);
    for (auto s : sums) cout << s << " ";
    cout << endl;
    return;
  }
  // x exists in the array and is not 0

}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
