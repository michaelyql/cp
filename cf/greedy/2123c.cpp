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
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vi pfx(n + 1), sfx(n + 2);
    pfx[0] = 1e9;
    sfx[n + 1] = -1e9;
    for (int i = 1; i <= n; i++) {
        pfx[i] = min(pfx[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        sfx[i] = max(sfx[i + 1], a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n) cout << "1";
        else if (a[i] == pfx[i] || a[i] == sfx[i]) cout << "1";
        else cout << "0";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
