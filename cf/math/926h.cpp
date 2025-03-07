#include <bits/stdc++.h>
// #include "helpers.cpp"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 2e5 + 7;
int b[N];
vector<int> r, o, w;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') r.push_back(b[i]);
    else if (s[i] == 'O') o.push_back(b[i]);
    else w.push_back(b[i]);
  }

  if (k == 1) {
    cout << -1 << endl;
    return 0;
  }

  sort(r.rbegin(), r.rend());
  sort(o.rbegin(), o.rend());
  sort(w.rbegin(), w.rend());

  // red-orange
  int p = 0, q = 0;
  ll sum1 = 0;
  if (r.size() + o.size() >= k && !r.empty() && !o.empty()) {
    for (int i = 1; i <= k; i++) {
      if (i == k) {
        if (p == 0) {
          // cout << r[p] << " ";
          sum1 += r[p++];
          break;
        } else if (q == 0) {
          // cout << o[q] << " ";
          sum1 += o[q++];
          break;
        }
        
      }

      if (p == r.size()) {
        // cout << o[q] << " ";
        sum1 += o[q++];
      } else {
        if (q == o.size() || r[p] >= o[q]) {
          // cout << r[p] << " ";
          sum1 += r[p++];
        } else {
          // cout << o[q] << " ";
          sum1 += o[q++];
        }
      }
    }
  }
  // cout<<": " << sum1 << endl;

  // white-orange
  ll sum2 = 0;
  p = 0, q = 0;
  if (w.size() + o.size() >= k && !w.empty() && !o.empty()) {
    for (int i = 1; i <= k; i++) {
      if (i == k) {
        if (p == 0) {
          // cout << w[p] << " ";
          sum2 += w[p++];
          break;
        } else if (q == 0) {
          // cout << o[q] << " ";
          sum2 += o[q++];
          break;
        }
      }

      if (p == w.size()) {
        // cout << o[q] << " ";
        sum2 += o[q++];
      } else {
        if (q == o.size() || w[p] >= o[q]) {
          // cout << w[p] << " ";
          sum2 += w[p++];
        } else {
          // cout << o[q] << " ";
          sum2 += o[q++];
        }
      }
    }
  } 
  // cout<<": " << sum2 << endl;
  // cout << "r: " << r;
  // cout << "o: " << o;
  // cout << "w: " << w;
  if (sum1 == 0 && sum2 == 0) {
    cout << -1 << endl;
  } else cout << max(sum1, sum2) << endl;
}

// Example: 
// K = 5
// R: 3, 4, 5, 5
// O: 2, 3, 5, 7
// W: 4, 6, 6

// Red-Orange: 7+5+5+5+4 = 26
// White-Orange: 7+6+6+5+4 = 28
