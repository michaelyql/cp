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
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    ll s = 0;
    for (int i = 0; i < n; i++) { 
        s += abs(a[i] - b[i]);
    }
    vector<pii> ranges;
    for (int i = 0; i < n; i++) {
        int l = min(a[i], b[i]);
        int r = max(a[i], b[i]);
        ranges.push_back({l, r});
    }
    sort(all(ranges), [](const pii& p1, const pii& p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    });
    
    int maxR = -2e9;
    int prevR = -2e9;
    ll best = 1e10;
    bool first = true;

    for (int i = 0; i < n; i++) {
        int l = ranges[i].first;
        int r = ranges[i].second;
        
        if (l <= maxR) {
            cout << s << endl;
            return;
        }

        if (!first) {
            ll gap = l - prevR;
            best = min(best, 2 * gap);
        }

        prevR = r;
        first = false;

        maxR = max(r, maxR);
    }
    cout << s + best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
