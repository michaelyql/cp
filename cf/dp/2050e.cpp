#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N][N] = { { 0 } };

string a, b, c;

int n; // length of a
int m; // length of b

int f(int i, int j) {
  if (i == 0 && j == 0) return 0;
  if (dp[i][j] != 0) return dp[i][j];
  int choose_a = INT_MAX, choose_b = INT_MAX;
  if (i > 0) choose_a = (a[i - 1] == c[i + j - 1] ? 0 : 1) + f(i - 1, j);
  if (j > 0) choose_b = (b[j - 1] == c[i + j - 1] ? 0 : 1) + f(i, j - 1);
  return dp[i][j] = min(choose_a, choose_b);
}

void solve() {
  cin >> a >> b >> c;
  n = a.length();
  m = b.length();
  memset(dp, 0, sizeof(dp));
  cout << f(n, m) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
