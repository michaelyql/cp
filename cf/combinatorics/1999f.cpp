#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int A[N];

void solve() {
  int n, k;
  cin >> n >> k;
  int ones = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] == 1) ones++;
  }
  if (ones <= k / 2) {
    cout << 0 << endl;
    return;
  }
  int zeros = n - ones;
  
  int ans = 0;
  // case where subsequence contains only 1's
  if (ones >= k) {
    
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
