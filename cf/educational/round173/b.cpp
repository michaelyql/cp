#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
  int n, d;
  cin >> n >> d;
  bool divisible_by_3 = d % 3 == 0 ? true : n >= 3;
  bool divisible_by_9 = d % 9 == 0 ? true : n < 6 ? (d % 3 == 0 && n >= 3) : true;
  bool divisible_by_5 = d % 5 == 0;
  bool divisible_by_7 = n >= 3 ? true : d == 7;
  cout << "1 ";
  if (divisible_by_3) cout << "3 ";
  if (divisible_by_5) cout << "5 ";
  if (divisible_by_7) cout << "7 ";
  if (divisible_by_9) cout << "9";
  cout << endl;
}

int main() {
  cin.sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
