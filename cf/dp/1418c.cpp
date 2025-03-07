#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  vvi dp(n + 1, vector<int>(2, 0));
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  for (int i = n - 1; i >= 0; i--) {
    dp[i][0] = dp[i + 1][1] + A[i];
    if (i + 2 <= n) dp[i][0] = min(dp[i][0], dp[i + 2][1] + A[i] + A[i + 1]);

    dp[i][1] = dp[i + 1][0];
    if (i + 2 <= n) dp[i][1] = min(dp[i][1], dp[i + 2][0]);
  }

  cout << dp[0][0] << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
