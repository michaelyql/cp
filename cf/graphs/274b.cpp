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

const int MAX_N = 1e5 + 7;
int a[MAX_N];
vi adj[MAX_N];
ll up[MAX_N], down[MAX_N];

void dfs(int u, int p = -1) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    ll max_up = 0, max_down = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        max_up = max(max_up, up[v]);
        max_down = max(max_down, down[v]);
    }
    ll x = a[u] + max_up - max_down;
    if (x > 0) {
        max_down += x;
    } else if (x < 0) {
        max_up -= x;
    }
    up[u] = max_up;
    down[u] = max_down;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    cout << up[1] + down[1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
