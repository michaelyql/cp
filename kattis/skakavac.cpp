#include <bits/stdc++.h>
#include <cmath>

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

struct comp {
    bool operator()(array<int, 3>& x, array<int, 3>& y) {
        return x[0] < y[0];
    }
};

struct maxST {
    vector<int> T;
    maxST() { 
        T = {}; 
    }
    maxST(int _n) {
        T.resize(4 * _n + 4, 0);
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            T[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, val);
            } else {
                update(v * 2 + 1, tm + 1, tr, pos, val);
            }
            T[v] = max(T[v * 2], T[v * 2 + 1]);
        }
    }
    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return 0;
        if (tl == ql && tr == qr) return T[v];
        int tm = (tl + tr) / 2;
        return max(
            query(v * 2, tl, tm, ql, min(qr, tm)), 
            query(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr)
        );
    }
};

void solve() {
    int n;
    cin >> n;
    int r, c;
    cin >> r >> c;
    vvi a(n, vi(n));
    priority_queue<array<int, 3>, vector<array<int, 3>>, comp> pq; 
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
            pq.push({a[i][j], i, j});
        }
    }

    vector<maxST> rows(n + 1); // max segtree for each row
    vector<maxST> cols(n + 1); // max segtree for each col
    rep(i, 1, n + 1) {
        rows[i] = maxST(n);
        cols[i] = maxST(n);
    }
    vector<vector<int>> dp(n, vector<int>(n, 1)); // dp[r][c] is max no. of flowers visitable starting from (r,c)

    while (!pq.empty()) {
        auto cell = pq.top(); pq.pop();
        int v = cell[0];
        vector<pii> cells;
        cells.push_back({cell[1], cell[2]});

        // batch same value cells together
        while (!pq.empty() && (pq.top())[0] == v) { 
            auto u = pq.top(); pq.pop();
            cells.push_back({u[1], u[2]});
        }

        // update dp of batch of cells
        for (auto& p : cells) {
            int row = p.first;
            int col = p.second;
            row++, col++; // make 1-indexed
            int best = 0;
            if (row > 1) { // row above
                best = max(best, rows[row - 1].query(1, 1, n, 1, col - 2)); 
                best = max(best, rows[row - 1].query(1, 1, n, col + 2, n)); 
            }
            if (row < n) { // row below
                best = max(best, rows[row + 1].query(1, 1, n, 1, col - 2)); 
                best = max(best, rows[row + 1].query(1, 1, n, col + 2, n));
            }
            if (col > 1) { // left col
                best = max(best, cols[col - 1].query(1, 1, n, 1, row - 2)); 
                best = max(best, cols[col - 1].query(1, 1, n, row + 2, n)); 
            }
            if (col < n) { // right col
                best = max(best, cols[col + 1].query(1, 1, n, 1, row - 2)); 
                best = max(best, cols[col + 1].query(1, 1, n, row + 2, n)); 
            }
            dp[row-1][col-1] = best + 1;
        }

        // update row and col ST
        for (auto& p : cells) {
            int row = p.first, col = p.second;
            row++, col++;
            rows[row].update(1, 1, n, col, dp[row-1][col-1]);
            cols[col].update(1, 1, n, row, dp[row-1][col-1]);
        }
    }
    cout << dp[r-1][c-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
