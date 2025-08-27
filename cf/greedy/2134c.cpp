#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
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
using uint = unsigned int;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

void solve() {
    int n;
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];

    ll forced = 0;
    vll b;

    for (int j = 0; j < n; j += 2) {
        ll u;
        if (j == 0) {
            if (n > 1) u = a[1];
            else u = LLONG_MAX; 
        } else if (j == n - 1) {
            u = a[n - 2];
        } else {
            u = min(a[j - 1], a[j + 1]);
        }
        ll bj = min(a[j], u);
        forced += a[j] - bj;
        b.push_back(bj);
    }

    int m = b.size();
    if (m <= 1) {
        cout << forced << endl;
        return;
    }

    vll t;
    for (int k = 0; k < m - 1; k++) {
        ll center_val = a[2 * k + 1];
        ll tk = b[k] + b[k + 1] - center_val;
        if (tk < 0) tk = 0;
        t.push_back(tk);
    }

    ll dp_prev2 = 0;
    ll dp_prev1 = t[0];
    for (int i = 1; i < (int) t.size(); i++) {
        ll cur = max(dp_prev1, dp_prev2 + t[i]);
        dp_prev2 = dp_prev1;
        dp_prev1 = cur;
    }
    ll extra = dp_prev1;

    cout << forced + extra << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
