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

const int MOD = 1e9 + 7;

const int MAX_N = 2e5 + 1;

ll fact[MAX_N];

void dfs(int u, int p, vvi& adj, vb& vis, vi& col, int cur_col, bool& ok) {
    vis[u] = true;
    col[u] = cur_col;

    for (int v : adj[u]) {
        if (v == p) continue;
        if (!vis[v]) {
            dfs(v, u, adj, vis, col, cur_col ^ 1, ok);
        } else {
            ok = false;
            return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    vi deg(n + 1, 0);
    vi col(n + 1, 0);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vb vis(n + 1, false);
    bool ok = true;
    dfs(1, -1, adj, vis, col, 0, ok);

    if (!ok) {
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    int l = 0, r = 0;
    for (int u = 1; u <= n; u++) {
        int cnt = 0; // number of nodes on opposite side with deg > 1

        if (deg[u] > 1) {
            if (col[u]) r++;
            else l++;

            // count children with deg 1 and permute them
            int c = 0;
            for (int v : adj[u]) {
                if (deg[v] == 1) c++;
                else cnt++;
            }

            if (cnt > 2) {
                // can't have more than 2 adjacent nodes with deg > 1
                cout << 0 << endl;
                return;
            }

            ans = ans * fact[c] % MOD;
        }
    }
    
    if (!l || !r) {
        cout << ans * 2 % MOD << endl;
    } else {
        cout << ans * 4 % MOD << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    rep(i, 1, MAX_N + 1) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int t;
    cin >> t;
    while (t--) solve();
}
