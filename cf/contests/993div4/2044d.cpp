#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<bool> appeared(n + 1, false);
  vector<int> A(n, 0);
  vector<int> res(n, 0);
  unordered_set<int> unincluded;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (!appeared[A[i]]) {
      res[i] = A[i];
      appeared[A[i]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!appeared[i]) {
      unincluded.insert(i);
    }
  }
  int distinct = n - unincluded.size();
  if (distinct == n) {
    for (int i = 0; i < n; i++) {
      cout << res[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (res[i] == 0) { 
      int x = *unincluded.begin();
      res[i] = x;
      unincluded.erase(x);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
