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
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    int total = accumulate(all(a), 0);
    vector<bool> dp(total + 1, false);
    dp[0] = true;
    rep(i, 1, n + 1) {
        vector<bool> next(total + 1, false);
        rep(j, 0, total + 1) {
            next[j] = dp[j];
            if (j - a[i] >= 0 && dp[j - a[i]]) next[j] = true;
        }
        dp = next;
    }
    int cnt = 0;
    rep(i, 1, total + 1) if (dp[i]) cnt++;
    cout << cnt << endl;
    rep(i, 1, total + 1) if (dp[i]) cout << i << " ";
}
