#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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

void ins(int x, int n, int k, multiset<int>& up, multiset<int>& low) {
  int v = *low.rbegin();
  if (x > v) {
    up.insert(x);
    if (up.size() > k / 2) {
      auto it = up.begin();
      low.insert(*it);
      up.erase(it);
    }  
  } else {
    low.insert(x);
    if (low.size() > (k + 1) / 2) {
      up.insert(v);
      low.erase(low.find(v));
    }
  }
}

void remove(int x, int n, int k, multiset<int>& up, multiset<int>& low) {
  auto it = low.find(x);
  if (it != low.end()) {
    low.erase(it);
  } else {
    it = up.find(x);
    up.erase(it);
  }
  if (low.empty()) {
    low.insert(*up.begin());
    up.erase(up.begin());
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	multiset<int> up, low;
  low.insert(a[0]);
  rep(i, 1, k) ins(a[i], n, k, up, low);
  cout << *low.rbegin() << " ";

  rep(i, 1, n - k + 1) {
    if (k == 1) {
      cout << a[i] << " ";
      continue;
    }
    remove(a[i - 1], n, k, up, low);
    ins(a[i + k - 1], n, k, up, low);
    cout << *low.rbegin() << " ";
  }
}
