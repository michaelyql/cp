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
int low[MAX_N], tin[MAX_N];
bool isBridge[MAX_N], vis[MAX_N];
vector<pii> g[MAX_N];
int n, m;

void dfs(int u, int p) {
    vis[u] = true;
    low[u] = tin[u] = ++timer;
    for (auto& e : g[u]) {
        int i, v;
        tie(i, v) = e;
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] < low[v]) {
                isBridge[i] = true;
            }
        }
    }
}

int comp[MAX_N];
vi G[MAX_N];

void dfs1(int u, int p, int id) {
    vis[u] = true;
    comp[u] = id;
    for (auto& e : g[u]) {
        int i, v;
        tie(i, v) = e;
        if (v == p || isBridge[i] || vis[v]) continue;
        dfs1(v, u, id);
    }
}

const int L = 20;
int up[MAX_N][L];
int tout[MAX_N], d[MAX_N];

void dfs2(int u, int p, int cur_dist) {
    // printf("dfs2 u=%d,p=%d,d=%d\n",u,p,cur_dist);
    tin[u] = ++timer;
    up[u][0] = p;
    d[u] = cur_dist;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v != p) {
            dfs2(v, u, cur_dist + 1);
        }
    }
    tout[u] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        // printf("u=%d,i=%d,up[u][i]=%d\n",u,i,up[u][i]);
        if (up[u][i] && !isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

pii edges[MAX_N];

void solve() {
    cin >> n >> m;
    rep(i, 0, m) { 
        int u, v; 
        cin >> u >> v; 
        g[u].push_back({i, v}); 
        g[v].push_back({i, u}); 
        edges[i] = {u, v};
    }
    dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    int id = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i, 0, id++);
        }
    }
    rep(i, 0, m) {
        if (isBridge[i]) {
            int u, v;
            tie(u, v) = edges[i];
            G[comp[u]].push_back(comp[v]);
            G[comp[v]].push_back(comp[u]);
            // printf("G(u=%d,comp[u]=%d,v=%d,comp[v]=%d)\n", u, comp[u], v, comp[v]);
        }
    }
    timer = 0;
    memset(tin, 0, sizeof(tin));
    dfs2(1, 0, 0);
    // for (int i = 1; i < id; i++) {
    //     printf("i=%d,tin=%d,tout=%d\n",i,tin[i],tout[i]);
    // }
    int k;
    cin >> k;
    rep(i, 0, k) {
        int u, v;
        cin >> u >> v;
        int w = lca(comp[u], comp[v]);
        // printf("u=%d,v=%d,comp[u]=%d,comp[v]=%d,lca=%d\n",u,v,comp[u],comp[v],w);
        // printf("tin[lca]=%d,tout[lca]=%d,tin[comp[u]]=%d,tout[comp[u]]=%d,tin[comp[v]]=%d,tout[comp[v]]=%d\n",
        //     tin[w],tout[w],tin[comp[u]],tout[comp[u]],tin[comp[v]],tout[comp[v]]);
        // printf("d[comp[u]]=%d,d[comp[v]]=%d,d[lca]=%d\n",d[comp[u]],d[comp[v]],d[w]);
        printf("%d\n",d[comp[u]] + d[comp[v]] - 2 * d[w]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
