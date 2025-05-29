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
    vi h(n), s(n);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, n) cin >> s[i];
    vi dp(x + 1, -1);
    dp[0] = 0;
    rep(i, 0, n) { 
        rep(j, 1, x + 1) { // j is current price
            if (j - h[i] >= 0 && dp[j - h[i]] != -1) {
                 dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
                 db(j)
                 db(dp[j])
            }
        }
    }
    rep(i, 1, x + 1) {db(dp[i]) db(i)}
    cout << dp[x] << endl;
}
