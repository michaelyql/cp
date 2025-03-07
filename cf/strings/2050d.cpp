#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    int curr = s[i] - '0';
    int idx = i;
    int maxFound = curr;
    for (int j = 1; j <= 8; j++) {
      if (i + j < n) {
        int candidate = s[i + j] - '0';
        if (candidate - j > maxFound) {;
          idx = i + j;
          maxFound = candidate - j;
        }
      }
    }
    if (idx > i) {
      for (int j = idx; j > i; j--) {
        char temp = s[j];
        s[j] = s[j -  1];
        s[j - 1] = --temp;
      }
    }
  }
  cout << s << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
