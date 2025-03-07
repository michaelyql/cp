#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 2e4 + 5;
int n;
int bit[N];

void update(int pos, int val) {
  for (; pos <= n; pos += pos & -pos) {
    bit[pos] += val;
  }
}

int query(int pos) {
  int res = 0;
  for (; pos > 0; pos -= pos & -pos) {
    res += bit[pos];
  }
  return res;
}

int find(int l, int r, int val = 0) {
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (query(mid) > val) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << "find: " << r << endl;
  return r;
}

void solve() {
  cin >> n;
  vector<int> ans(n + 1, 0); // 1 based index answer
  memset(bit, 0, n + 2);
  cout << "---"<<endl;
  // originally all 1s, turn to 0 when filled
  for (int i = 1; i <= n; i++) update(i, 1); 
  cout << "starting bit: ";
  for (int i = 1; i <= n; i++) cout << bit[i] << " "; cout << endl;

  int cur = 2; // current index
  ans[cur] = 1; // card 1 placed at position 2
  update(cur, -1);

  for (int i = 2; i <= n; i++) { // i = number of steps to jump
    int a = query(cur); // left side empty
    int b = query(n) - a; // right side empty

    cout << "(cur: " << cur << ", i: " << i << ", a: " << a << ", b: " << b << ", ";
    cout << "bit: ";
    for (int i = 1; i <= n; i++) cout << bit[i] << " "; cout << "), ans: ";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    if (a == 0) {
      
    } else if (b == 0) {
    
    } else {
      int insert = (i + 1) % (a + b);
      if (insert <= b && insert > 0) {
        // end up on right side
        cur = find(cur + 1, n, a);
      } else {
        // end up on left side
        cur = find(0, cur - 1);
      }
    }
    update(cur, -1); 
    ans[cur] = i;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  // cin.sync_with_stdio(false);
  // cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
