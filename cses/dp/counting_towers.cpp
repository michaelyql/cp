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
const int N = 1e6;

int add(int x, int y) {
    return (x % MOD + y % MOD) % MOD;
}

int mul(int x, int y) {
    return (int) (1ll * x * y % MOD);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    vvi dp(N + 1, vi(2, 0));

    dp[1][0] = dp[1][1] = 1;
    rep(i, 2, N + 1) {
        // merge 
        dp[i][1] = add(dp[i - 1][0], mul(dp[i - 1][1], 2));

        // don't merge
        dp[i][0] = add(dp[i - 1][1], mul(dp[i - 1][0], 4));
    }

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << add(dp[n][0], dp[n][1]) << endl;
    }
}
