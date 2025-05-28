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
    int n, x;
    cin >> n >> x;

    vi c(n);
    rep(i, 0, n) cin >> c[i];
    
    const int MOD = 1e9 + 7;

    vector<ll> dp(x + 1);
    dp[0] = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < n; j++) {
            if (i + c[j] <= x && dp[i] != 0) dp[i + c[j]] = (dp[i + c[j]] + dp[i]) % MOD;
        }
    }

    cout << dp[x] << endl;
}
