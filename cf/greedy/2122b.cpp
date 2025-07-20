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
    int n;
    cin >> n;
    vi a(n), b(n), c(n), d(n);
    rep(i, 0, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    ll move1 = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > d[i]) move1 += a[i];
        else {
            if (a[i] > c[i]) move1 += a[i] - c[i];
        }
    }
    ll move2 = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > d[i]) move2 += b[i] - d[i];
    }
    cout << move1 + move2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
