#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

#define umap unordered_map

const int N = 2e5 + 5;
int a[N], h[N], pref[N];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    memset(pref, 0, n + 2);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    if (n == 1) {
      if (a[0] <= k) cout << 1 << endl;
      else cout << 0 << endl;
      continue;
    }
    bool check_one = false; // check range of 1
    for (int i = 0; i < n; i++) {
      if (a[i] <= k) {
        check_one = true;
        break;
      }
    }
    if (!check_one) {
      cout << 0 << endl;
      continue;
    }
    int l = 1, r = n;
    while (l < r) { // l represents a valid answer, r is used to narrow down the space until it meets l
      int m = l + (r - l) / 2;
      if (r == l + 1) m = r; // prevent infinite loop
      // cout << "l:"<<l<<endl;
      // cout << "m:"<<m<<endl;
      // cout << "r:"<<r<<endl;
      
      bool ok = false; // whether or not the current segment size m is valid

      bool prev = false; // whether the previous range from [i, i + m - 1] was valid
      
      for (int i = 0; i < n - m + 1; ) {
        // cout << "i:"<<i<<endl;

        bool divide = true; 
        
        int j = i;

        if (prev) { // instead of checking the whole [i + 1, i + m], just check the next element 
          if (h[i + m - 2] % h[i + m - 1] != 0) {
            divide = false;
            prev = false;
          } 
        } else { // otherwise, we need to start checking the whole of [i, i + m - 1]
          for (; j < i + m - 1; j++) {
            if (h[j] < h[j + 1] || h[j] % h[j + 1] != 0) {
              divide = false;
              break;
            }
          }
        }

        if (m == 0) divide = false;
        
        if (divide) { // the whole segment of length m is valid
          if (pref[i + m] - pref[i] <= k) { 
            // cout<<"i+m:"<<i+m<<endl;
            // cout << "sum" << pref[i + m] - pref[i] <<endl;
            ok = true;
            break;
          }
          else {
            prev = true;
            i++;
          }
        } 
        else {
          i = j + 1; // we only start checking from the start of the next segment since it's
          // pointless to check up till the index j which is already not divisible
          prev = false; // meaning that the previous segment [i, i + m - 1] did not form a valid range
        }
      }
      
      if (ok) {
        l = m; // l always represents a valid answer
      }
      else {
        r = m - 1; 
      }
    }
    cout << l << endl;
  }
}
