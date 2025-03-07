#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> v(n, 0);
  string line;
  int l = 0, r = 10e4;
  cin.ignore(); // ignore trailing newline char
  while (m--) {
    getline(cin, line);
    int idx = line[line.length() - 1] - '0' - 1; // make index 0 based
    if (line.find("left") != string::npos) {
      if (idx <= r) r = idx - 1;
      if (idx <= l) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      if (idx >= l) l = idx + 1;
      if (idx >= r) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if (r == 10e4) r = n-1;
  cout << (r - l + 1) << endl;
}
