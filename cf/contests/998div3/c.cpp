#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  
  // cout << "d0" << endl;
  int less = lower_bound(x.begin(), x.end(), k) - x.begin();

  int l = 0, r = less - 1;
  
  int score = 0;
  // cout << "d1" << endl;

  while (l < r) {
    if (l == r - 1) {
      if (x[l] + x[r] == k) score++;
      break;
    }
    if (x[l] + x[r] == k) {
      // cout << "d2" << endl;
      score++;
      l++;
      r--;
    } else if (x[l] + x[r] < k) {
      // cout << "d3" << endl;
      while (l < r - 1 && x[l] + x[r] < k) l++;
      if (l == r - 1) continue;
      if (x[l] + x[r] == k) {
        score++;
        l++;
        r--;
      } 
    } else {
      // cout << "d4" << endl;
      // cout << "r: " << r << ", l: " << l << ", k: " << k << ", x[l]: " << x[l] << ", x[r]: " << x[r] << endl;
      while (r > l + 1 && x[l] + x[r] > k) r--;
      if (l == r - 1) continue;
      if (x[l] + x[r] == k) {
        score++;
        l++;
        r--;
      } 
    }
  }
  
  cout << score << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
