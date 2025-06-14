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

ll t[4 * MAX_N], a[MAX_N];

void update(int v, int l, int r, int ql, int qr, int x) {
    if (ql > qr) return;
    if (l == ql && r == qr) {
        t[v] += x;
    } else {
        int m = (l + r) / 2;
        update(v * 2, l, m, ql, min(m, qr), x);
        update(v * 2 + 1, m + 1, r, max(m + 1, ql), qr, x);
    }
}

ll query(int v, int l, int r, int k) {
    if (l == r) {
        return t[v] + a[k];
    }
    int m = (l + r) / 2;
    if (k <= m) {
        return t[v] + query(v * 2, l, m, k);
    } else {
        return t[v] + query(v * 2 + 1, m + 1, r, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, q;
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, q) {
        int c;
        cin >> c;
        if (c == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            update(1, 0, n - 1, a, b, u);
        } else {
            int k;
            cin >> k;
            k--;
            cout << query(1, 0, n - 1, k) << endl;
        }
    }
}
