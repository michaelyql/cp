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

random_device rnd;
mt19937 mt(rnd());
// usage: shuffle(all(a), mt)
// usage: uint32_t r = mt()

void solve() {
    ll a, b;
    cin >> a >> b;
    ll ans = -1;
    auto check = [&](ll k) {
        if (k == 0) return;
        if (b % k != 0) return;
        ll s = a * k + b / k;
        if (s % 2 == 0) ans = max(ans, s);
    };

    check(1);
    check(b);

    ll temp = b;
    int t = 0;
    while (temp % 2 == 0) {
        temp /= 2;
        t++;
    }

    ll k1 = 1;
    for (int s = 1; s <= t; s++) {
        k1 *= 2;
        check(k1);
        check(b / k1);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
