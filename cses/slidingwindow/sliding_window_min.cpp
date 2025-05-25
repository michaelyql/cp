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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, k;
	cin >> n >> k;

  ll x, a, b, c;
  cin >> x >> a >> b >> c;

	vi v(n);
  rep(i, 0, n) {
    v[i] = x;
    x = (a * x % c + b) % c;
  }

  deque<int> q;
  q.push_back(v[0]);

  // first window
  for (int i = 1; i < k; i++) {
    while (!q.empty() && v[i] < q.back()) {
      q.pop_back();
    }
    q.push_back(v[i]);
  }
  int ans = q.front();
  
  for (int i = 1; i < n - k + 1; i++) {
    if (k == 1) {
      ans ^= v[i];
      continue;
    }
    if (q.front() == v[i - 1]) {
      q.pop_front();
    }
    while (!q.empty() && v[i + k - 1] < q.back()) {
      q.pop_back();
    }
    q.push_back(v[i + k - 1]);
    ans ^= q.front();
  }
  cout << ans;
}
