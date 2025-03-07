#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map
#define fori(a, b) for (size_t i = a; i <= b; i++)

const int N = 2e5 + 7;
int A[N];
umap<int, int> cnt;

void solve() {
  int n;
  cin >> n;
  fori(1, n) {
    cin >> A[i];
    A[i] -= i;
    cnt[A[i]]++;
  }
  ll ans = 0;
  fori(1, n) {
    if (cnt[A[i]]) {
      ans += (1ll * cnt[A[i]] * (cnt[A[i]] - 1)) / 2;
      cnt[A[i]] = 0;
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
