#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

int A[201];

int main() {
  // generate random permutation from 1 to 200
  int sz = 200;
  random_device rd;
  mt19937 g(rd());
  iota(A, A + sz, 1);
  shuffle(A, A + sz, g);
  cout << sz << endl;
  for (int i = 0; i < sz; i++) cout << A[i] << " ";
  cout << endl;
}
