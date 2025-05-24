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
  map<int, set<int>> mp;
  unordered_map<int, int> freq;

  // first window
  for (int i = 0; i < k; i++) freq[a[i]]++;
  for (int i = 0; i < k; i++) mp[freq[a[i]]].insert(a[i]);
	cout << *((*(mp.rbegin())).second.begin()) << " ";
  
  for (int i = 1; i < n - k + 1; i++) {
    if (a[i - 1] != a[i + k - 1]) {
      mp[freq[a[i - 1]]].erase(a[i - 1]);
      if (mp[freq[a[i - 1]]].empty()) mp.erase(freq[a[i - 1]]);
      freq[a[i - 1]]--;
      mp[freq[a[i - 1]]].insert(a[i - 1]);

      mp[freq[a[i + k - 1]]].erase(a[i + k - 1]);
      if (mp[freq[a[i + k - 1]]].empty()) mp.erase(freq[a[i + k - 1]]);
      freq[a[i + k - 1]]++;
      mp[freq[a[i + k - 1]]].insert(a[i + k - 1]);
    } 
	  cout << *((*(mp.rbegin())).second.begin()) << " ";
  }
}
