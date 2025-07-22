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

const int M = 998244353;

ll modexp(ll x, ll e) {
    ll res = 1;
    x %= M;
    while (e) {
        if (e & 1) res = res * x % M;
        x = x * x % M;
        e >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return modexp(a, M - 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi l(n), r(n), p(n), q(n), w(n);
    ll p0 = 1;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
        ll x = p[i] % M * inv(q[i] % M) % M;    
        ll y = (1 - x + M) % M;
        w[i] = x * inv(y) % M;
        p0 = p0 * y % M;
    }

    vll dp(m + 1);
    dp[0] = 1;
    vvi ends(m + 1);
    for (int i = 0; i < n; i++) {
        ends[r[i]].push_back(i);
    }

    for (int x = 1; x <= m; x++){
        ll s = 0;
        for (int i : ends[x]) {
            s = (s + dp[l[i]-1] * w[i]) % M;
        }
        dp[x] = s;
    }

    ll ans = p0 * dp[m] % M;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(); 
}
