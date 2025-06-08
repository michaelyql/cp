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

ll dp[19][10][2][2];

ll solve(const string& num, int pos, int prev_digit, bool tight, bool leading_zero) {
    if (pos == num.size()) return 1;
    if (dp[pos][prev_digit][tight][leading_zero] != -1) return dp[pos][prev_digit][tight][leading_zero];
    int limit = tight ? num[pos] - '0' : 9;
    ll ans = 0;
    for (int d = 0; d <= limit; d++) { 
        if (!leading_zero && d == prev_digit) continue;
        bool next_tight = tight && d == limit;
        bool next_leading_zero = leading_zero && d == 0;
        ans += solve(num, pos + 1, d, next_tight, next_leading_zero);
    }
    return dp[pos][prev_digit][tight][leading_zero] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll a, b;
    cin >> a >> b;
    rep(i, 0, 19) rep(j, 0, 10) rep(k, 0, 2) rep(l, 0, 2) dp[i][j][k][l] = -1;
    ll x = solve(to_string(b), 0, 0, true, true);
    rep(i, 0, 19) rep(j, 0, 10) rep(k, 0, 2) rep(l, 0, 2) dp[i][j][k][l] = -1;
    ll y = (a == 0) ? 0 : solve(to_string(a - 1), 0, 0, true, true);
    cout << x - y << endl;
}
