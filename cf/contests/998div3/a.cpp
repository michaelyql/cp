#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

void solve() {

}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    
    int a3 = a1 + a2;
    int ans1 = 1, ans2 = 1, ans3 = 1;
    if (a2 + a3 == a4) {
      ans1++;
    }
    if (a3 + a4 == a5) ans1++;

    a3 = a4 - a2;
    if (a1 + a2 == a3) ans2++;
    if (a3 + a4 == a5) ans2++;

    a3 = a5 - a4;
    if (a1 + a2 == a3) ans3++;
    if (a4 - a2 == a3) ans3++;
    cout << max(ans3, max(ans1, ans2)) << endl;
  }
}
