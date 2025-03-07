#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 101;
unordered_map<char, int> cnt[N];

int main() {
  cin.sync_with_stdio(false);
  string t;
  cin >> t;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      cnt[i][c]++;
    }
  }
  
}
