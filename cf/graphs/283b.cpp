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

int n;

void dfs(int u, int t, vi& a, vi& fwd, vi& back, vvll& score, vector<vb>& vis) {
    if (vis[u][t]) {
        score[u][t] = -1;
        return;
    }
    int next = t ? fwd[u] : back[u];
    if (next == 1) {
        // you can only travel backwards to reach 1
        // so when you reach 1, it moves forward again
        // so it necessarily forms a cycle
        // there is no case of ever reaching 1 from a forward move
        score[u][t] = -1; 
        return;
    }
    if (next <= 0 || next > n) {
        score[u][t] = a[u];
        return;
    }
    vis[u][t] = true;
    if (!score[next][t ^ 1]) dfs(next, t ^ 1, a, fwd, back, score, vis);
    if (score[next][t ^ 1] == -1) {
        score[u][t] = -1;
    } else {
        score[u][t] = a[u] + score[next][t ^ 1];
    }
    vis[u][t] = false;
}

void solve() {
    cin >> n;
    vi a(n + 1);
    vi fwd(n + 1), back(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        fwd[i] = i + a[i];
        back[i] = i - a[i];
    }
    vvll score(n + 1, vll(2, 0));
    vector<vb> vis(n + 1, vb(2, false));

    for (int i = 2; i <= n; i++) {
        for (int t = 0; t < 2; t++) {
            if (!score[i][t]) dfs(i, t, a, fwd, back, score, vis);
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        if (score[1 + i][0] != -1) {
            cout << score[1 + i][0] + i << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
