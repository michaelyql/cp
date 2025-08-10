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

void dfs1(int u, int p, vvi& adj, vi& deg, vi& leaves) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (deg[v] == 1) leaves[u]++;
        else {
            dfs1(v, u, adj, deg, leaves);
            leaves[u] += leaves[v];
        }
    }
}

void dfs2(int u, int p, vvi& adj, vi& leaves, vi& cost, vi& deg, int parent_leaves, int& ans) {
    int d = 0;
    for (auto v : adj[u]) {
        if (v == p) {
            cost[u] += parent_leaves;
        } else {
            cost[u] += leaves[v];
        }
        if (deg[v] == 1) d++;
    }
    ans = min(ans, cost[u]);

    for (auto v : adj[u]) {
        if (v == p) continue;

        int par_leaves = cost[u] - leaves[v] + d;

        dfs2(v, u, adj, leaves, cost, deg, par_leaves, ans);
    }
}

void solve() {
    int n;
    cin >> n;
    vvi adj(n + 1);
    vi deg(n + 1), leaves(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    dfs1(1, 0, adj, deg, leaves);
    int ans = n;
    vi cost(n + 1);
    dfs2(1, 0, adj, leaves, cost, deg, 0, ans);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
