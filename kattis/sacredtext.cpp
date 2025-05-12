#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using vi = vector<int>;
using ll = long long;

int main() {
  string s;
  char c;
  cin >> s;
  cin >> c;
  int v = 0;
  for (char cc : s) {
    v += cc - 32;
  }
  int d = v - (c - 'a' + 1);
  while (getline(cin, s)) {
    istringstream iss(s);
    string rune;
    vector<char> runes;
    while (iss >> rune) {
      if (rune == "0") {
        runes.push_back(' ');
        continue;
      }
      if (rune == "<") {
        runes.push_back(',');
        continue;
      }
      if (rune == ">") {
        runes.push_back('.');
        continue;
      }
      v = 0;
      for (char cc : rune) {
        v += cc - 32;
      }
      v -= d;
      if (v <= 0) v += 26;
      else if (v > 26) v -= 26;
      runes.push_back(char('a' + v - 1));
    }
    for (char cc : runes) cout << cc;
    cout << endl;
  }
}
