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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1) {
        cout << l << endl;
        return;
    }
    if (n == 2 || l == r) {
        cout << -1 << endl;
        return;
    }
    bool ok = false;
    for (int i = 62; i >= 0; i--) {
        ll a = l & (1ll << i);
        ll b = r & (1ll << i);
        if (!a && !b) {
            continue;
        }
        if ((a && !b) || (!a && b)) {
            ok = true;
            break;
        }
        if (a && b) {
            break;
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    int j = 0;
    for (int i = 62; i >= 0; i--) {
        if (l & (1ll << i)) {
            j = i;
            break;
        }
    }
    ll b = 1ll << (j + 1);
    if (k <= n - 2) cout << l << endl;
    else cout << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
