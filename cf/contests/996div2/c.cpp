#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

ll a[2002][2002];

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<ll> rowSum(n);
  vector<ll> colSum(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      rowSum[i] += a[i][j];
      colSum[j] += a[i][j];
    }
  }

  ll prev_val; // value of previous visited cell
  int r, c; // current row and column 

  if (s[0] == 'D') {
    prev_val = a[0][0] = -rowSum[0];
    r = 1, c = 0;
  } else {
    prev_val = a[0][0] = -colSum[0];
    r = 0, c = 1;
  }

  for (int i = 1; i < n + m - 2; i++) {
    if (s[i - 1] == 'D' && s[i] == 'D') {
      colSum[c] += prev_val;
      prev_val = a[r][c] = -rowSum[r];
      r++;
    } else if (s[i - 1] == 'D' && s[i] == 'R') {
      prev_val = a[r][c] = -(colSum[c] + prev_val);
      c++;
    } else if (s[i - 1] == 'R' && s[i] == 'D') {
      prev_val = a[r][c] = -(rowSum[r] + prev_val);
      r++;
    } else { // s[i - 1] == 'R' && s[i] == 'R'
      rowSum[r] += prev_val;
      prev_val = a[r][c] = -colSum[c];
      c++;
    }
  } 

  if (s.back() == 'R') {
    a[n - 1][m - 1] = -colSum[m - 1];
  } else {
    a[n - 1][m - 1] = -rowSum[n - 1];
  }
 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  /* 
  
  Debug

  for (int i = 0; i < n; i++) {   
    rowSum[i] = 0;
  }
  for (int j = 0; j < m; j++) {   
    colSum[j] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      rowSum[i] += a[i][j];
      colSum[j] += a[i][j];
    }
  }
  cout << "Row sum: ";
  for (int i = 0; i < n; i++) {   
    cout << rowSum[i] << " ";
  }
  cout << endl;
  cout << "Col sum: ";
  for (int j = 0; j < m; j++) {   
    cout << colSum[j] << " ";
  }
  cout << endl;
  */
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
