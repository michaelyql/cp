#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  string copy = s;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'p') copy[n - 1 - i] = 'q';
    else if (s[i] == 'q') copy[n - 1 - i] = 'p';
    else copy[n - 1 - i] = 'w';
  }
  cout << copy << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
