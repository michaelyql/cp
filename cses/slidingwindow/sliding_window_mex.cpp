#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
#define debug
 
#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, k;
	cin >> n >> k;
	vi a(n);
  rep(i, 0, n) cin >> a[i];
  vector<int> v(n + 1);
  iota(all(v), 0); // 
  set<int> mex_candidates(all(v));

  unordered_map<int, int> freq;
  // first window
  for (int i = 0; i < k; i++) {
    freq[a[i]]++;
    if (mex_candidates.find(a[i]) != mex_candidates.end()) {
      mex_candidates.erase(a[i]);
    }
  }
  cout << *(mex_candidates.begin()) << " ";

  for (int i = 1; i < n - k + 1; i++) {
    if (a[i - 1] != a[i + k - 1]) {
      freq[a[i + k - 1]]++;
      if (mex_candidates.find(a[i + k - 1]) != mex_candidates.end()) {
        mex_candidates.erase(a[i + k - 1]);
      }

      if (freq[a[i - 1]] == 1) {
        mex_candidates.insert(a[i - 1]);
      }
      freq[a[i - 1]]--;
    } 
    cout << *(mex_candidates.begin()) << " ";
  }
}
