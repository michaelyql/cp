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
    int s, f;
    vector<pii> events;
    while (cin >> s >> f) {
        if (s == 0 && f == 0) break;
        events.push_back({s, f});
    }
    int n = events.size(), ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<bool> used(10);
        bool ok = true;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                cnt++;
                int start = events[j].first;
                int end = events[j].second;
                for (int k = start; k < end; k++) {
                    if (used[k]) {
                        ok = false;
                        break;
                    }
                    used[k] = true;
                }
            }
            if (!ok) break;
        }
        if (ok) ans = max(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
