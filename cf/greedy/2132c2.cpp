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

ll cost[20];

void solve() {
    ll n, k;
    cin >> n >> k;

    ll cur = n;

    ll ans = 0;
    int deals = 0;
    vector<ll> used(19); 

    ll p = pow(3ll, 18);
    for (int i = 18; i >= 0; i--) {
        if (p <= cur) {
            // used 
            ll x = cur / p;

            ans += x * cost[i];
            cur -= x * p;
            deals += x;

            used[i] = x;
        }
        p /= 3;
    }
    if (deals > k) {
        cout << -1 << endl;
        return;
    } 
    for (int i = 18; i >= 1; i--) {
        if (used[i]) {
            ll x = min((k - deals) / 2, used[i]);
            ans = ans - x * cost[i] + 3 * x * cost[i - 1];
            deals += x * 2;
            used[i - 1] += x * 3;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (ll i = 0; i < 19; i++) {
        cost[i] = pow(3ll, i + 1) + i * pow(3ll, i - 1);
    }

    int t;
    cin >> t;
    while (t--) solve();
}
