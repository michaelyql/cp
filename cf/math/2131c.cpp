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
    int n, k;
    cin >> n >> k;
    vi s(n), t(n);
    map<pii, int> s_grps, t_grps;
    rep(i, 0, n) {
        cin >> s[i];
        int x = s[i] % k;
        int y = abs(x - k);
        if (x > y) swap(x, y);
        s_grps[{x, y}]++;
    } 
    rep(i, 0, n) {
        cin >> t[i];
        int x = t[i] % k;
        int y = abs(x - k);
        if (x > y) swap(x, y);
        t_grps[{x, y}]++;
    } 
    for (auto it = s_grps.begin(); it != s_grps.end(); it++) {
        auto key = it->first;
        if (t_grps.find(key) == t_grps.end()) {
            cout << "NO\n"; 
            return;
        }
        int f = t_grps[key];
        if (it->second != f) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
