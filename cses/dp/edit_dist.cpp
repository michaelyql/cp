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

const int inf = 1e9 + 7;

int solve(int i, int j, string& a, string& b, vvi& dp) {
    if (dp[i][j] != inf) return dp[i][j];
    if (a[i] == b[j]) {
        return dp[i][j] = solve(i - 1, j - 1, a, b, dp);
    } else {
        return dp[i][j] = min(1 + solve(i - 1, j - 1, a, b, dp), 
        					  1 + min(solve(i - 1, j, a, b, dp), 
        							  solve(i, j - 1, a, b, dp)));
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    a = " " + a;
    b = " " + b;
    vvi dp(n + 1, vi(m + 1, inf));
    rep(i, 0, m + 1) dp[0][i] = i;
    rep(i, 0, n + 1) dp[i][0] = i;
    cout << solve(n, m, a, b, dp) << endl;
}
