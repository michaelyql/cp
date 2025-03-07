#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 2e5 + 5;
int a[N];
const int LOG = 20; 
int st[LOG][N]; // sparse table

// 2^10 = 1e3
// 2^20 = 1e6
// 2^19 = ~5e5

void build(int n) {
  for (int i = 0; i < n - 1; i++) { // for interval size of 2^1 = 2
    // st[1][i] = ;
  }
  for (int pw = 2; pw <= n; pw *= 2) {

  }
}

int query(int l, int r) {

}

void solve() {
  int n, q;
  cin >> n >> q;
  memset(st, 0, LOG * (n + 1));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(n);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << " ";
  }
  cout << endl;
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
