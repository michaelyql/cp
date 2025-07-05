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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (b < a) {
        if (b == a - 1 && (a & 1)) {
            cout << y << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (b == a) {
        cout << 0 << endl;
    } else {
        if (x <= y) {
            cout << (b - a) * x << endl;
        } else {
            int ans = 0;
            for (int i = a; i < b; i++) {
                if (i & 1) ans += x;
                else ans += y;
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
