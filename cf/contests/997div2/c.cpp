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
  if (n == 6) {
    cout << "1 1 2 3 1 2" << endl;
  }
  else {
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) {
        cout << i << " ";
      }
      for (int i = 1; i <= n / 2; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      for (int i = 1; i <= n / 2 + 1; i++) {
        cout << i << " ";
      }
      for (int i = 1; i <= n / 2; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
