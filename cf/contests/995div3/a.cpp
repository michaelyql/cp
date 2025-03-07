#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {

}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (i == n - 1) sum += a[i];
      else {
        if (a[i] > b[i + 1]) sum += a[i] - b[i + 1];
      }
    }
    cout << sum << endl;
  }
}
