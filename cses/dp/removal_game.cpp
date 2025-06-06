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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

const ll NO_ANS = -1e18;

ll solve(int i, int j, int n, int turn, vll& a, vvll& dp, vll& psum) {
    if (i == j) return turn ? 0 : a[i];
    if (dp[i][j] != NO_ANS) return dp[i][j];
    int next_turn = (turn + 1) % 2;
    if (turn) {
        ll x = solve(i + 1, j, n, next_turn, a, dp, psum);
        ll y = solve(i, j - 1, n, next_turn, a, dp, psum);
        ll s1 = a[i] + psum[j + 1] - psum[i + 1] - x;
        ll s2 = a[j] + psum[j] - psum[i] - y;
        return dp[i][j] = s1 > s2 ? x : y;
    } else {
        return dp[i][j] = max(
            a[i] + solve(i + 1, j, n, next_turn, a, dp, psum),
            a[j] + solve(i, j - 1, n, next_turn, a, dp, psum)
        );
    }
}

int main() {
    int n;
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    vll psum(n + 1);
    rep(i, 1, n + 1) psum[i] = psum[i - 1] + a[i - 1];
    vvll dp(n, vll(n, NO_ANS));
    cout << solve(0, n - 1, n, 0, a, dp, psum) << endl;
}
