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

int n, a;

void solve() {
    if (a == 0) {
        cout << n << endl;
        return;
    }
    vector<vector<pair<int, bool>>> says(n);
    for (int j = 0; j < a; j++) {
        int x, y;
        cin >> x >> y;
        x--;
        int k = abs(y) - 1;
        if (y > 0) {
            says[x].push_back({k, true});
        } else {
            says[x].push_back({k, false});
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        bool valid_mask = true;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cnt++;
                for (int j = 0; j < says[i].size(); j++) {
                    int k = says[i][j].first;
                    if (says[i][j].second) {
                        if (!(mask & (1 << k))) {
                            valid_mask = false;
                            break;
                        }
                    } else {
                        if (mask & (1 << k)) {
                            valid_mask = false;
                            break;
                        }
                    }
                }
            } 
            if (!valid_mask) break;
        }
        if (valid_mask) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n >> a) {
        if (n == 0 && a == 0) break;
        solve();
    }
}
