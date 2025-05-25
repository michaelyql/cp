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

  // first window
  ll temp = 0;
  rep(i, 0, k) temp ^= v[i];
  
  ll ans = temp;

  rep(i, 1, n - k + 1) {
    temp ^= v[i - 1] ^ v[i + k - 1];
    ans ^= temp;
  }
  
  cout << ans << endl;
  
}
