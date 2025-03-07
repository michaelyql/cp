#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int prefix[N];
int dp[N];

int f(int x) {
  if (dp[x]) return dp[x];
  if (x == 0) return 0;
  return dp[x] = 1 + f(x / 3);
} 

void solve() {
  int l, r;
  cin >> l >> r;
  cout << f(l) * 2 + prefix[r] - prefix[l] << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i < N; i++) {
    prefix[i] = prefix[i - 1] + f(i);
  }
  while (t--) solve();
}
