#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
// #define debug

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
using uint = unsigned int;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

void solve() {
    bp(---)
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> dp(n + 1);
    map<int, vector<int>> mp;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1];
        if (a[i] == 1) {
            dp[i]++;
            db(a[i])
            db(dp[i])
        } else {
            db(i)
            db(a[i])
            mp[a[i]].push_back(i);
            if (mp[a[i]].size() >= a[i]) {
                int p = mp[a[i]].size() - a[i];
                db(p)
                db(mp[a[i]][p])
                int q = mp[a[i]][p];
                db(dp[q + 1]);
                dp[i] = max(dp[i], dp[q + 1] + a[i]);
            }
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
