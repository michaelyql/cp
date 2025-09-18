#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
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

random_device rnd;
mt19937 mt(rnd());
// usage: shuffle(all(a), mt)
// usage: uint32_t r = mt()

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vll a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vll vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int)vals.size();
    map<ll, int> comp;
    for(int i = 0; i < m; ++i) comp[vals[i]] = i + 1;

    vector<map<int, ll>> cur(m+1), nxt(m+1);
    cur[0][0] = 1; 

    for(int i = 0; i < n; ++i){
        int v = comp[a[i]];
        for(int x = 0; x <= m; ++x) nxt[x].clear();

        for(int x = 0; x <= m; ++x){
            for(const auto &p : cur[x]){
                int y = p.first;
                ll cnt = p.second;

                ll &slotSkip = nxt[x][y];
                slotSkip += cnt;
                if(slotSkip >= mod) slotSkip -= mod;

                if(x == 0 || x <= v){
                    ll &slot = nxt[v][y];
                    slot += cnt;
                    if (slot >= mod) slot -= mod;
                } else if (y == 0 || y <= v){
                    ll &slot = nxt[x][v];
                    slot += cnt;
                    if (slot >= mod) slot -= mod;
                }
            }
        }
        cur.swap(nxt);
    }

    ll ans = 0;
    for (int x = 0; x <= m; ++x){
        for (const auto &p : cur[x]){
            ans += p.second;
            if (ans >= mod) ans -= mod;
        }
    }
    cout << ans % mod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
