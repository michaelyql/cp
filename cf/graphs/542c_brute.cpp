#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const int N = 205;
vector<int> A(N), cur_state(N);

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    cur_state[i] = A[i];
  }
  bool flag = true;
  int k = 1;
  while (flag) {
    for (int i = 1; i <= n; i++) {
      if (cur_state[i] != cur_state[cur_state[i]]) {
        flag = true;
        break;
      } else {
        flag = false;
      }
    }
    if (flag) {
      k++;
      for (int i = 1; i <= n; i++) cur_state[i] = A[cur_state[i]];
    } 
  }
  cout << k << endl;
}
