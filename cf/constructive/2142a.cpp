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
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vi b = a;
    sort(all(b));
    vector<bool> ok(n);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) ok[i] = true, c++;
    }
    if (c >= 2) {
        cout << "YES" << endl;
        cout << c << endl;
        for (int i = 0; i < n; i++) {
            if (ok[i]) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
