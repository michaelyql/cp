#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
// #define debug

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

void solve() {
    bp(---)
    int n;
    cin >> n;
    vvi g(n + 1);
    vi indeg(n + 1);
    rep(i, 0, n - 1) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if (u > v) swap(x, y);
        if (x > y) {
            g[v].push_back(u);
            indeg[u]++; 
        } else {
            g[u].push_back(v);
            indeg[v]++;
        }
    }
    vi order;
    queue<int> q;
    rep(i, 1, n + 1) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    } 
    vi p(n + 1);
    rep(i, 1, n + 1) p[order[i - 1]] = i;
    rep(i, 1, n + 1) cout << p[i] << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
