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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> pa(n + 1), pb(m + 1);
    for (int i = 1; i <= n; i++) pa[i] = pa[i - 1] + a[i - 1];
    for (int i = 1; i <= m; i++) pb[i] = pb[i - 1] + b[i - 1];

    auto S = [&](int i, int z) -> ll {
        // cout << "i="<<i<< endl;
        return pa[n] - pa[n - i] + pb[m] - pb[m-(z-i)];
    };
    
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        int L = max(0, max(z - m, z - y));
        int R = min(z, min(x, n));

        int l = L, r = R;
        while (r - l > 3) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (S(m1, z) < S(m2, z)) l = m1;
            else r = m2;
        } 
        ll ans = -1e18;
        for (int i=l; i<=r; i++) ans = max(ans, S(i,z));
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
