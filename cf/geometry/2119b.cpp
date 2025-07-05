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
    int n, px, py, qx, qy;
    cin >> n >> px >> py >> qx >> qy;
    vll a(n);
    ll s = 0, m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        m = max(m, a[i]);
    }

    ll dx = px - qx;
    ll dy = py - qy;
    ll d = dx * dx + dy * dy;
    if (s * s < d) {
        cout << "No" << endl;
        return;
    }
    ll low = max(0ll, 2 * m - s);
    if (low * low <= d && d <= s * s) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
