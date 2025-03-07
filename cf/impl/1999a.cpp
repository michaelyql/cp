#include <bits/stdc++.h>
using namespace std;

void solve() {

}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s) {
      ans += c - '0';
    }
    cout << ans << endl;
  }
}
