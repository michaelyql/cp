#include <bits/stdc++.h>
using namespace std;

void solve() {

}

const int N = 51;
int A[N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool has_zero = false;
    bool has_nonzero = false;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      if (A[i] == 0) has_zero = true;
      else has_nonzero = true;
    }
    if (has_zero && !has_nonzero) {
      cout << 0 << endl;
      continue;
    }
    if (has_nonzero && !has_zero) {
      cout << 1 << endl;
      continue;
    }
    int first = 0, last = n - 1;
    for (int i = 0; i < n; i++) {
      if (A[i] != 0) {
        first = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (A[i] != 0) {
        last = i;
        break;
      }
    }
    bool sandwiched = false;
    while (first < last - 1) {
      int next = first + 1;
      if (A[next] == 0) {
        sandwiched = true;
        break;
      }
      first++;
    }
    if (sandwiched) cout << 2;
    else cout << 1;
    cout << endl;
  }
}
