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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

const int MAX_N = 1e5 + 5;
int timer = 0;
int low[MAX_N], disc[MAX_N];
bool vis[MAX_N], isBridge[MAX_N];
void dfs(int u, int p, vector<vector<pii>>& g) {
    low[u] = disc[u] = ++timer;
    vis[u] = true;
    for (auto& e : g[u]) {
        int i, v;
        tie(i, v) = e;
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            dfs(v, u, g);
            low[u] = min(low[u], low[v]);
            if (disc[u] < low[v]) {
                isBridge[i] = true;
            }
        }
    }
}

int comp[MAX_N];
void dfs1(int u, int p, vector<vector<pii>>& g, int id) {
    comp[u] = id;
    vis[u] = true;
    for (auto& e : g[u]) {
        int i, v;
        tie(i, v) = e;
        if (v == p || vis[v] || isBridge[i]) continue;
        dfs1(v, u, g, id);
    }
}

void dfs2(int u, int p, vvi& G, int d, int& w, int& maxd) {
    vis[u] = true;
    if (d > maxd) {
        maxd = d;
        w = u;
    }
    for (int v : G[u]) {
        if (v == p || vis[v]) continue;
        dfs2(v, u, G, d + 1, w, maxd);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> edges(m);
    vector<vector<pii>> g(n + 1);
    vvi G(n + 1);
    memset(vis, 0, sizeof(vis));
    memset(isBridge, 0, sizeof(isBridge));
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        g[u].push_back({i, v});
        g[v].push_back({i, u});
    }
    dfs(1, 0, g);
    memset(vis, 0, sizeof(vis));
    int id = 1;
    rep(i, 1, n + 1) {
        if (!vis[i]) {
            dfs1(i, 0, g, id);
            id++;
        }
    }
    int bridges = 0;
    rep(i, 0, m) {
        int u, v;
        tie(u, v) = edges[i];
        if (isBridge[i]) {
            G[comp[u]].push_back(comp[v]);
            G[comp[v]].push_back(comp[u]);
            bridges++;
        }
    }
    memset(vis, 0, sizeof(vis));
    int w, maxd = 0;
    dfs2(1, 0, G, 0, w, maxd);
    memset(vis, 0, sizeof(vis));
    dfs2(w, 0, G, 0, w, maxd);
    cout << bridges - maxd << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
