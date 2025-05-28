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
	int n;
  cin >> n;

  const int MOD = 1e9 + 7;

  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
  }

  cout << dp[n] << endl;
}
