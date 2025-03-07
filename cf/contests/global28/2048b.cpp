#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
      continue;
    }
    vector<int> a(n, 0);
    int cur = 1;
    for (int i = k - 1; i < n; i += k) {
      a[i] = cur++;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) a[i] = cur++;
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
