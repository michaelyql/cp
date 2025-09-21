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

bool dfs(int u, vector<bool>& vis, vvi& g, vi& val) {
    vis[u] = true;
    for (int v : g[u]) {
        int want = val[u] ^ 1;
        if (val[v]==-1) {
            val[v]=want;
            if (!dfs(v, vis, g, val)) return false;
        } else if (val[v] != want) return false;
        if (!vis[v]) { 
            vis[v]=true; 
            if (!dfs(v,vis,g,val)) return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> edges;
    vi val(n, -1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            bool left_unfilled = (i-1 >= 0) && s[i-1] == '0';
            bool right_unfilled = (i+1 < n) && s[i+1] == '0';
            if (left_unfilled && right_unfilled) {
                edges.push_back({i-1,i+1});
            }
            else if (left_unfilled) {
                if (val[i-1] == -1) val[i-1] = 0;
                else if (val[i-1] != 0) ok = false;
            }
            else if (right_unfilled) {
                if (val[i+1] == -1) val[i+1] = 1;
                else if (val[i+1] != 1) ok = false;
            }
        } 
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    vvi g(n);
    for (auto& x : edges) {
        g[x.first].push_back(x.second);
        g[x.second].push_back(x.first);
    }
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && val[i] != -1 && !vis[i]) {
            if (!dfs(i, vis, g, val)) {
                cout << "NO" << endl;
                return;
            }
        } 
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && val[i] == -1) {
            val[i] = 0;
            if (!dfs(i, vis, g, val)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
