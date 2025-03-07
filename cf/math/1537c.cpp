#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 2e5 + 7;
int H[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> H[i];
  }
  sort(H, H + n);
  int p = 0;
  int mindiff = 2e9;
  for (int i = 0; i < n - 1; i++) {
    if (H[i + 1] - H[i] < mindiff) {
      p = i;
      mindiff = H[i + 1] - H[i];
    }
  }
  cout << H[p] << " ";
  for (int i = p + 2; i < n; i++) {
    cout << H[i] << " ";
  }
  for (int i = 0; i < p; i++) {
    cout << H[i] << " ";
  }
  cout << H[p + 1] << endl;
}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
