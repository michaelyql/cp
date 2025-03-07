#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map



int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int i = 0, j = 0;
  map<int, int> freq;
  ll ans = 0;
  while (i < n) {
     freq[a[i]]++;
     while (freq.size() > k && j < i) {
      freq[a[j]]--;
      if (freq[a[j]] == 0) {
        freq.erase(a[j]);
      }
      j++;
     }
     ans += i - j + 1;
     i++;
  }
  cout << ans << endl;
}
