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

ll f(ll x) {
    int p[4] = {2, 3, 5, 7};
    ll tot = 0;
    for (int m = 1; m < 16; m++) {
        int cnt = 0;
        int pow = 1;
        for (int j = 0; j < 4; j++) {
            if (m & (1 << j)) {
                cnt++;
                pow *= p[j];
            }
        }
        if (cnt & 1) {
            tot -= x / pow;
        } else {
            tot += x / pow;
        }
    }
    return x + tot;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
