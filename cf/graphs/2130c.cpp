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

void dfs(int u, int p, vvi& adj, vb& vis, vb& ok, map<pii, int>& indices) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            int a = u, b = v;
            if (a > b) swap(a, b);
            int i = indices[{a, b}];
            ok[i] = false;
        } else {
            dfs(v, u, adj, vis, ok, indices);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vvi adj(2 * n + 1);
    map<pii, int> indices;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        indices[{a, b}] = i;
    }
    vb vis(2 * n + 1, false);
    vb ok(n + 1, true);
    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i] && !adj[i].empty()) {
            dfs(i, -1, adj, vis, ok, indices);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (ok[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
