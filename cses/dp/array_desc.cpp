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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    return (x % MOD + y % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];

    vvi dp(n + 1, vi(m + 2, 0));

    if (a[1] == 0) rep(i, 1, m + 1) dp[1][i] = 1;
    else dp[1][a[1]] = 1;

    rep(i, 2, n + 1) {
        if (a[i] != 0) {
            dp[i][a[i]] = add(dp[i - 1][a[i]], add(dp[i - 1][a[i] + 1], dp[i - 1][a[i] - 1]));
        } else {
            rep(j, 1, m + 1) {
                dp[i][j] = add(dp[i - 1][j], add(dp[i - 1][j + 1], dp[i - 1][j - 1]));
            }
        }
    }
    int ans = 0;
    rep(i, 1, m + 1) ans = add(ans, dp[n][i]);
    cout << ans << endl;
}
