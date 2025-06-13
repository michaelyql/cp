#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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
using vvll = vector<vll>;

const int inf = 1e9 + 5;
const int MAX_N = 2e5 + 5;

int t[4 * MAX_N], a[MAX_N];

void build(int pos, int tl, int tr) {
    if (tl == tr) {
        t[pos] = a[tl];
    } else {
        int m = (tl + tr) / 2;
        build(pos * 2, tl, m);
        build(pos * 2 + 1, m + 1, tr);
        t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
    }
}

int query(int pos, int tl, int tr, int l, int r) {
    if (l > r) {
        return inf;
    }
    if (tl == l && tr == r) {
        return t[pos];
    }
    int tm = (tl + tr) / 2;
    return min(
        query(pos * 2, tl, tm, l, min(r, tm)), 
        query(pos * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
    );
}

void update(int i, int pos, int v, int tl, int tr) {
    if (tl == tr) {
        t[pos] = v;
    } else {
        int tm = (tl + tr) / 2;
        if (i <= tm) {
            update(i, pos * 2, v, tl, tm);
        } else {
            update(i, pos * 2 + 1, v, tm + 1, tr);
        }
        t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    rep(i, 0, MAX_N * 4) t[i] = inf;
    int n, q;
    cin >> n >> q;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    build(1, 1, n);
    rep(i, 0, q) {
        int c;
        cin >> c;
        if (c == 1) {
            int k, u;
            cin >> k >> u;
            update(k, 1, u, 1, n);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
        }
    }
}
