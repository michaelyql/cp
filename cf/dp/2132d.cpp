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

ll sum(ll n) {
    if (n <= 0) return 0;
    ll res = 0;
    for (ll p = 1; p <= n; p *= 10) {
        ll high = n / (p * 10);
        ll cur = n / p % 10;
        ll low = n % p;
        res += high * 45 * p;
        res += cur * (low + 1);
        res += (cur * (cur - 1) / 2) * p;
    }
    return res;
}

int f(ll x, int leftover) {
    string s = to_string(x);
    int sum = 0;
    int sz = s.size();
    for (int i = 0; i < leftover && i < sz; i++) {
        sum += s[i] - '0';
    }
    return sum;
}

void solve() {
    ll k;
    cin >> k;

    auto A = [](int d) {
        ll tot = 0;
        for (int j = 1; j <= d; j++) {
            tot += 9ll * pow(10ll, j - 1) * j;
        }
        return tot;
    };
    int d = 1;
    while (A(d) < k) d++;

    ll b = A(d - 1);
    ll m = (k - b) / d;
    ll n = pow(10ll, d - 1) - 1 + m;
    ll used = b + m * d;

    int leftover = k - used;
    ll ans = sum(n);
    if (leftover > 0) ans += f(n + 1, leftover);
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
