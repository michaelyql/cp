#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 1e3 + 5;
int perm[N];

void solve() {
  int n;
  cin >> n;
  string s;
  memset(perm, 0, n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int pos = 1;
    for (int j = 1; j < i; j++) {
      if (s[j - 1] == '1') pos++; 
    }
    int c = n - i;
    for (int j = i + 1; j <= n; j++) {
      if (s[j - 1] == '1') c--;
    }
    pos += c;
    // cout << "Pos: " << pos << ", i: " << i << endl;
    perm[pos] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << perm[i] << " ";
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
