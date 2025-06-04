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
    int a, b;
    cin >> a >> b;
    const int inf = 1e9 + 7;
    if (a > b) swap(a, b);
    vvi dp(a + 1, vi(b + 1, inf));

    rep(i, 0, a + 1) dp[i][i] = 0;

    rep(i, 1, a + 1) {
        rep(j, 1, b + 1) {
            if (i == j) continue;
            rep(k, 1, j + 1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            rep(k, 1, i + 1) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        }
    }
    cout << dp[a][b] << endl;
}
