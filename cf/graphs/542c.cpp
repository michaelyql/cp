#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const int N = 202;
int A[N];
bool vis[N];

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  ull max_d = 0;
  ull ans = 1;
  for (int i = 1; i <= n; i++) {
    memset(vis, false, n + 1);
    stack<int> s;
    s.push(i);
    vis[i] = true;
    int next = A[i];
    while (!vis[next]) {
      s.push(next);
      vis[next] = true; 
      next = A[next];
    }
    ull cycle_size = 1;
    while (!s.empty() && s.top() != next) {
      s.pop();
      cycle_size++;
    }
    // cout << "cycle size: " << cycle_size << endl;
    ans = (ans / gcd(ans, cycle_size)) * cycle_size; // ans is a multiple of the lcm of all cycle sizes 
    // divide first, then multiply, to avoid potential overflow error
    if (!s.empty()) s.pop();
    max_d = max(max_d, (ull)s.size()); // maximum distance to a cycle of a node not in a cycle
  }
  ull temp = ans;
  // cout << "max_d: " << max_d << endl;
  // cout << "ans: " << ans << endl;
  while (ans < max_d) {
    ans += temp;
  }
  cout << ans << endl;
}
