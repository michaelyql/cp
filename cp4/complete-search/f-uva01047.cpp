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

int n, k;
int tc = 0;

void solve() {
    tc++;
    cout << "Case Number  " << tc << "\n";
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    int m;
    cin >> m;
    unordered_map<int, int> overlap;
    rep(i, 0, m) {
        int t;
        cin >> t;
        int mask = 0;
        rep(j, 0, t) {
            int tower;
            cin >> tower;
            tower--;
            mask |= (1 << tower);
        }
        int o;
        cin >> o;
        overlap[mask] = o;
    }
    int max_c = 0, reco = 1 << 21;
    for (int mask = 1; mask < (1 << n); mask++) {
        int c = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                c += a[i];
                cnt++;
            }
        }
        if (cnt != k) continue; 
        for (auto& p : overlap) {
            int new_mask = mask & p.first;
            if (new_mask) {
                int n_tower = 0;
                for (int i = 0; i < n; i++) {
                    if (new_mask & (1 << i)) n_tower++;
                }
                c -= p.second * (n_tower - 1);
            }
        }

        if (c > max_c) {
            max_c = c;
            reco = mask;
        } else if (c == max_c) {
            for (int i = 0; i < n; i++) {
                int a = mask & (1 << i);
                int b = reco & (1 << i);
                if (a && b == 0) {
                    reco = mask;
                } else if (b && a == 0) {
                    break;
                }
            }
        }
    }

    cout << "Number of Customers: " << max_c << "\n";
    cout << "Locations recommended: ";
    vector<int> towers;
    for (int i = 0; i < n; i++) {
        if (reco & (1 << i)) towers.push_back(i + 1);
    }
    // presentation error due to extra space is so godddamn stupid
    rep(i, 0, towers.size() - 1) cout << towers[i] << " ";
    cout << towers.back();
    cout << "\n\n";
}

int main() {
    while((cin >> n >> k) && n && k) {
        solve();
    }
}
