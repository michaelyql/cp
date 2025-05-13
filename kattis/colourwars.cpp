#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using vi = vector<int>;
using ll = long long;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> mp;
  ll ans = 0;
  int x;
  rep(i, 0, n) {
    cin >> x;
    if (mp[x] == 0) {
      ans += x + 1;
      mp[x] = x;
    } else {
      mp[x]--;
    }
  }
  cout << ans << endl;
}
