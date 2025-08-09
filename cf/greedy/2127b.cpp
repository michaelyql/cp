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
using uint = unsigned int;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

void solve() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int l = 0, r = 0;
    x--;
    int maxl = -1, minr = n;
    for (int i = 0; i < x; i++) {
        if (s[i] == '#') l++, maxl = i;
    }
    for (int i = n - 1; i > x; i--) {
        if (s[i] == '#') r++, minr = i;
    }
    if (l == 0 && r == 0) {
        cout << 1 << endl;
        return;
    }
    // db(l)
    // db(r)
    // db(maxl)
    // db(minr)
    if (l && r) {
        if (maxl == x - 1 || minr == x + 1) {
            cout << min(x + 1, n - x) << endl;
            return;
        }
        if (maxl + 2 < n - minr + 1) {
            cout << min(x + 1, n - minr + 1) << endl; 
        } else {
            cout << min(n - x, maxl + 2) << endl;
        }
    }
    if (!l) {
        cout << min(x + 1, n - minr + 1) << endl; 
        return;
    } 
    if (!r) {
        cout << min(n - x, maxl + 2) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
