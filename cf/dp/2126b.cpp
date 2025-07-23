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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vector<bool> ok(n + 1, false);
    int bad = 0;
    for (int i = 0; i < k; i++) {
        bad += a[i];
    }
    if (bad == 0) ok[0] = true;
    for (int i = 1; i < n - k + 1; i++) {
        bad -= a[i -  1];
        bad += a[i + k - 1];
        if (bad == 0) ok[i] = true;
    }
    vi dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (ok[i]) {
            dp[i] = max(1 + dp[i + k + 1], dp[i + 1]);
        } else {
            dp[i] = dp[i + 1];
        }
    }
    cout << dp[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
