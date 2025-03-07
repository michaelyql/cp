#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 1e5 + 7;
pair<int, int> A[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    A[i] = {a, i};
  }
  sort(A + 1, A + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (1ll * A[i].first * A[j].first > 2 * n) break;
      if (A[i].first * A[j].first == A[i].second + A[j].second) ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
