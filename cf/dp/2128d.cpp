#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
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
using vb = vector<bool>;

void solve() {
    int n;
    cin >> n;
    vi p(n);
    rep(i, 0, n) cin >> p[i];
    ll s = 1;
    vll dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (p[i] > p[i + 1]) {
            dp[i] = dp[i + 1] + (n - i);
        } else {
            dp[i] = dp[i + 1] + 1;
        }
        s += dp[i];
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
