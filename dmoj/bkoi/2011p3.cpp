#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void incr(int &v, vector<bool> &used, int &n) {
  while (v < 2 * n && used[v]) v++;
}

void decr(int &v, vector<bool> &used, int &n) {
  while (v > 0 && used[v]) v--;  
}

int main() {
  int n;
  cin >> n;
  int b; 
  cin >> b;
  vector<int> a(2 * n - 1);
  a[0] = b;
  vector<bool> used(2 * n);
  used[b] = true;

  int vmin = 1;
  int vmax = 2 * n - 1;
  int prev = b;

  if (a[0] == vmin) vmin++;
  else if (a[0] == vmax) vmax--;

  int x = 1, y = 2;

  for (int i = 1; i < n; i++) {
    cin >> b;
    // cout << "b: " << b << ", prev: " << prev << ", vmin: " << vmin << ", vmax: " << vmax << endl;
    if (b == prev) {
      a[x] = vmin;
      a[y] = vmax;
      used[vmin] = used[vmax] = true;
      // cnt[vmin]++;
      // cnt[vmax]++;
    } else if (b < prev) {
      a[x] = vmin;
      used[vmin] = true;
      // cnt[vmin]++;

      if (!used[b]) {
        a[y] = b;
        used[b] = true;
        // cnt[b]++;
      } else {
        incr(vmin, used, n);
        a[y] = vmin;
        used[vmin] = true;
        // cnt[vmin]++;
      }
      
    } else {
      a[x] = vmax;
      used[vmax] = true;
      // cnt[vmax]++;
     
      if (!used[b]) {
        a[y] = b;
        used[b] = true;
        // cnt[b]++;
      } else {
        decr(vmax, used, n);
        a[y] = vmax;
        used[vmax] = true;
        // cnt[vmax]++;
      }

    }
    prev = b;
    incr(vmin, used, n);
    decr(vmax, used, n);
    x += 2;
    y += 2;

    // cout << "a: ";
    // for (int j = 0; j < i * 2 + 1; j++) {
    //   cout << a[j] << ", ";
    // }
    // cout << endl;
  }

  for (int i = 0; i < 2 * n - 1; i++) {
    cout << a[i] << " ";
  }

  // cout << endl;
  // for (int i = 1; i <= 2 * n - 1; i++) {
  //   cout << i << ": " << (used[i] ? ((cnt[i] > 1) ? "used multiple times" : "used") : "not used") << endl;
  // }
}
