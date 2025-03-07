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
    int n = s.length();
    int ones_cnt = count(s.begin(), s.end(), '1');
    if (ones_cnt == n) {
      cout << 1 << " " << n << " 1 1" << endl;
      continue;
    } 
    if (ones_cnt == 1) {
      cout << 1 << " " << n << " " << 1 << " " << n - 1 << endl;
      continue;
    }
    int first_zero_idx = 1;
    while (s[first_zero_idx] == '1') first_zero_idx++;
    int substr_len = n - first_zero_idx;

    string a = s.substr(first_zero_idx, substr_len);

    string prev_best(substr_len, '0');
    for (int i = 0; i < substr_len; i++) {
      if ((a[i] == '0' && s[i] == '1') || (a[i] == '1' && s[i] == '0')) prev_best[i] = '1';
    }

    int idx = 0;
    for (int i = 1; i < n - substr_len + 1; i++) {
      string b = s.substr(i, substr_len);
      for (int j = 0; j < substr_len; j++) {
        if ((a[j] == '0' && b[j] == '1') || (a[j] == '1' && b[j] == '0')) b[j] = '1';
        else b[j] = '0';
      }
      for (int j = 0; j < substr_len; j++) {
        if (b[j] == '0' && prev_best[j] == '1') break;
        if (b[j] == '1' && prev_best[j] == '0') {
          prev_best = b;
          idx = i;
          break;
        } 
      }
    }

    idx++;
    cout << 1 << " " << n << " " << idx << " " << idx + substr_len - 1 << endl;
  }
}
