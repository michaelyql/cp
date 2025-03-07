#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 105;
int A[N];
int ans;

void solve() {
  int n, k;
  cin >> n >> k;
  vvi remainder(k);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    remainder[A[i] % k].push_back(i);
  }
  int ans = -1;
  for (int i = 0; i < k; i++) {
    if (remainder[i].size() == 1) {
      ans = remainder[i][0];
      break;
    }
  }
  if (ans == -1) cout << "NO" << endl;
  else cout << "YES" << endl << ans << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
