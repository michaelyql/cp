#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) {
        cout << i << " " << i << " ";
      }
      continue;
    } else {
      if (n < 27) {
        cout << -1 << endl;
        continue;
      }
      vector<int> a(n, -1);
      a[1] = a[17] = a[26] = 1;
      a[0] = a[4] = 2;
      int k = 3;
      bool incr = false;
      for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
          cout << a[i] << " ";
          continue;
        } else {
          cout << k << " ";
          if (incr) {
            k++;
            incr = false;
          } else {
            incr = true;
          }
        }
      }
      cout << endl;
    }
  }
}
